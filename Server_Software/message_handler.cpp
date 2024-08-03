#include "MessageHandler.h"
#include <random>
#include <iostream>
#include "FileUtils.h"
#include <thread>
#include <mutex>


// Helper function to generate random user IDs
std::string generateRandomUserId()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(100000, 999999);
    return "user" + std::to_string(dist(mt));
}

void MessageHandler::onRequest(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response)
{
    response.headers()
        .add<Pistache::Http::Header::AccessControlAllowOrigin>("*")
        .add<Pistache::Http::Header::AccessControlAllowMethods>("GET, POST, OPTIONS")
        .add<Pistache::Http::Header::AccessControlAllowHeaders>("Content-Type, Accept");

    if (request.method() == Pistache::Http::Method::Post)
    {
        handlePost(request, std::move(response));
    }
    else if (request.method() == Pistache::Http::Method::Options)
    {
        handleOptions(request, std::move(response));
    }
    else
    {
        response.send(Pistache::Http::Code::Method_Not_Allowed, "Method Not Allowed");
    }
}


std::mutex dataMutex; // Mutex for protecting shared resources

void processRequest(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response)
{
    try
    {
        auto body = nlohmann::json::parse(request.body());

        // Log the received JSON data
        std::cout << "Received JSON data: " << body.dump(4) << std::endl;

        // Load existing patient data
        std::unordered_map<std::string, Patient> patients;
        std::vector<FoodCategory> temp;
        loadDataFromFile("users_data.json", temp, patients, PATIENTS);

        if (body.contains("feedback_score") && body.contains("userId"))
        {
            // Handle feedback score
            std::string userId = body.at("userId").get<std::string>();
            float feedbackScore = body.at("feedback_score").get<float>();
            std::cout << "Received feedback score: " << feedbackScore << std::endl;

            // Update the feedback score for the user
            std::lock_guard<std::mutex> lock(dataMutex); // Lock to ensure thread safety
            if (patients.find(userId) != patients.end())
            {
                patients[userId].setFeedback(feedbackScore);
                // Save the updated patient data
                saveDataToFile("users_data.json", temp, patients, PATIENTS);
                response.send(Pistache::Http::Code::Ok, "Feedback updated successfully");
            }
            else
            {
                response.send(Pistache::Http::Code::Not_Found, "User not found");
            }
            return;
        }

        // Ensure all required keys are present
        if (!(body.contains("name") && body.contains("age") && body.contains("gender") &&
              body.contains("height") && body.contains("weight") && body.contains("diseases")))
        {
            response.send(Pistache::Http::Code::Bad_Request, "Missing required fields");
            return;
        }

        // Generate or retrieve the user ID
        std::string userId = body.contains("userId") ? body.at("userId").get<std::string>() : generateRandomUserId();

        // Parse patient data from JSON
        std::string name = body.at("name").get<std::string>();
        int age = body.at("age").get<int>();
        std::string gender = body.at("gender").get<std::string>();
        float height = body.at("height").get<float>();
        float weight = body.at("weight").get<float>();

        // Parse diseases
        std::vector<Disease> diseases;
        for (const auto &diseaseName : body.at("diseases"))
        {
            diseases.emplace_back(diseaseName.get<std::string>(), ""); // Add descriptions if available
        }

        // Create a Patient object
        Patient patient;
        patient.setUserId(userId);
        patient.setName(name);
        patient.setAge(age);
        patient.setGender(gender);
        patient.setHeight(height);
        patient.setWeight(weight);
        patient.setDiseases(diseases);

        // Generate diet plan for the patient
        DietPlan dietPlan(patient);

        // Store the patient in the map
        std::lock_guard<std::mutex> lock(dataMutex); // Lock to ensure thread safety
        patients[userId] = patient;

        // Save the received JSON data to a file
        saveDataToFile("users_data.json", temp, patients, PATIENTS);

        nlohmann::json jsonData;
        jsonData["userId"] = userId;
        jsonData["diet_plan"] = dietPlan.getPlan();

        // Send the response as a stringified JSON
        response.send(Pistache::Http::Code::Ok, jsonData.dump(4));
    }
    catch (const std::exception &e)
    {
        // Send an error response if parsing fails
        response.send(Pistache::Http::Code::Bad_Request, std::string("Failed to process request: ") + e.what());
    }
}

void MessageHandler::handlePost(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response)
{
    // Create a new thread for processing the request
    std::thread(&processRequest, request, std::move(response)).detach();
}

void MessageHandler::handleOptions(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response)
{
    response.headers()
        .add<Pistache::Http::Header::AccessControlAllowOrigin>("*")
        .add<Pistache::Http::Header::AccessControlAllowMethods>("GET, POST, OPTIONS")
        .add<Pistache::Http::Header::AccessControlAllowHeaders>("Content-Type, Accept");

    response.send(Pistache::Http::Code::No_Content);
}

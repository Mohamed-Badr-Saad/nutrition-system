#include "FileUtils.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include "FoodItem.h"
#include "DietPlan.h"
using namespace std;
using namespace nlohmann;

// Function to save data to a JSON file
void saveDataToFile(const string &filename, const vector<FoodCategory> &categories, const unordered_map<string, Patient> &patients, int savedContent)
{
    json j;

    if (savedContent == CATEGORIES)
    {
        // Save categories
        for (const auto &category : categories)
        {
            json categoryJson;
            categoryJson["name"] = category.getName();
            for (const auto &item : category.getItems())
            {
                json itemJson;
                itemJson["name"] = item.getName();
                itemJson["category"] = category.getName();
                itemJson["calories"] = item.getCalories();
                itemJson["protein"] = item.getProtein();
                itemJson["carbs"] = item.getCarbs();
                itemJson["fats"] = item.getFat();
                categoryJson["items"].push_back(itemJson);
            }
            j["categories"].push_back(categoryJson);
        }
    }
    else if (savedContent == PATIENTS)
    {
        // Save patients and their diet plans
        for (const auto &patientPair : patients)
        {
            const Patient &patient = patientPair.second;
            json patientJson;
            patientJson["userId"] = patient.getUserId();
            patientJson["name"] = patient.getName();
            patientJson["age"] = patient.getAge();
            patientJson["gender"] = patient.getGender();
            patientJson["height"] = patient.getHeight();
            patientJson["weight"] = patient.getWeight();
            patientJson["feedback"] = patient.getFeedback();

            for (const auto &disease : patient.getDiseases())
            {
                patientJson["diseases"].push_back(disease.getName());
            }

            // Generate and save diet plan
            DietPlan dietPlan(patient);
            patientJson["dietPlan"] = dietPlan.getPlan();

            j["patients"].push_back(patientJson);
        }
    }

    ofstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    file << j.dump(4); // Pretty print JSON
}

// Function to load data from a JSON file
void loadDataFromFile(const string &filename, vector<FoodCategory> &categories, unordered_map<string, Patient> &patients, int savedContent)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    json j;
    try
    {
        file >> j;
    }
    catch (const json::parse_error &e)
    {
        cerr << "JSON parse error: " << e.what() << endl;
        return;
    }

    if (savedContent == CATEGORIES)
    {
        // Load categories
        for (const auto &categoryJson : j["categories"])
        {
            auto category = FoodCategory(categoryJson["name"]);
            for (const auto &itemJson : categoryJson["items"])
            {
                category.addItem(FoodItem(
                    itemJson["name"],
                    itemJson["category"],
                    itemJson["calories"],
                    itemJson["protein"],
                    itemJson["carbs"],
                    itemJson["fats"]));
            }
            categories.emplace_back(category);
        }
    }
    else if (savedContent == PATIENTS)
    {
        // Load patients
        for (const auto &patientJson : j["patients"])
        {
            vector<Disease> diseases;
            std::string diseaseDescription = "Description of the disease";
            for (const auto &diseaseName : patientJson["diseases"])
            {
                diseases.push_back(Disease(diseaseName, diseaseDescription));
            }

            Patient patient(
                patientJson["userId"],
                patientJson["name"],
                patientJson["age"],
                patientJson["gender"],
                patientJson["height"],
                patientJson["weight"],
                diseases,
                patientJson["feedback"]);
            
            patients[patient.getUserId()] = patient;
        }
    }
}

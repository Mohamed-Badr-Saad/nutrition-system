#include "DietPlan.h"
#include <cstdlib>
// Constructor that initializes the diet plan based on the provided patient
DietPlan::DietPlan(const Patient &patient)
{
    generatePlan(patient);
}

// Adds a meal to the plan for a specific day
void DietPlan::addMeal(const std::string &day, const std::string &meal, const std::vector<FoodItem> &items)
{
    // Ensure day and meal keys exist
    if (plan.find(day) == plan.end())
    {
        plan[day] = json::object();
    }
    if (plan[day].find(meal) == plan[day].end())
    {
        plan[day][meal] = json::array();
    }

    // Add the food items to the specified meal
    for (const auto &item : items)
    {
        plan[day][meal].push_back(item.getName());
    }
}

string DietPlan::getPlan() const
{
    return plan.dump(4); // Return the JSON as a formatted string
}

void DietPlan::generatePlan(const Patient &patient)
{
    // Example: Generate a diet plan for each day of the week
    vector<FoodItem> breakfast = {
        (categories[0].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS],
        (categories[1].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS],
        (categories[2].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS],
        (categories[3].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS]};
    vector<FoodItem> lunch = {
        (categories[0].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS],
        (categories[1].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS],
        (categories[2].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS],
        (categories[3].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS]};
    vector<FoodItem> dinner = {
        (categories[0].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS],
        (categories[1].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS],
        (categories[2].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS],
        (categories[3].getItems())[rand() % TOTAL_NUM_OF_FOOD_ITEMS]};

    // Loop over each day of the week
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for (const auto &day : days)
    {
        addMeal(day, "Breakfast", {breakfast[rand() % 4], breakfast[rand() % 4]});
        addMeal(day, "Lunch", {lunch[rand() % 4], lunch[rand() % 4]});
        addMeal(day, "Dinner", {dinner[rand() % 4], dinner[rand() % 4]});
    }
}
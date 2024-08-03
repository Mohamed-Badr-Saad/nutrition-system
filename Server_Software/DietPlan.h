#ifndef DIETPLAN_H
#define DIETPLAN_H

#include <string>
#include <vector>
#include "FoodItem.h"
#include "Patient.h"
#include"FoodCategory.h"
#include <nlohmann/json.hpp> // Include the JSON library
extern vector<FoodCategory> categories;
#define TOTAL_NUM_OF_FOOD_ITEMS 6
using namespace std;
using namespace nlohmann;

class DietPlan {
public:
    DietPlan(const Patient& patient);

    void addMeal(const string& day, const string& meal, const vector<FoodItem>& items);
    string getPlan() const ;


private:
    json plan; // Change to JSON object to accommodate multiple days
    void generatePlan(const Patient& patient);
};

#endif // DIETPLAN_H

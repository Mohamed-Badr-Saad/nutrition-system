#include "Patient.h"
#include "Disease.h"
#include "FoodCategory.h"
#include "FoodItem.h"
#include <vector>
#include "FileUtils.h"

using namespace std;

void initializeData(vector<FoodCategory> &foodCategories)
{

    // Initializing food categories and items
    FoodCategory fruits("Fruits");
    fruits.addItem(FoodItem("Apple", 52, 14, 0.3, 0.2, {"Vitamins", "Fibers"}));
    fruits.addItem(FoodItem("Banana", 89, 23, 1.1, 0.3, {"Potassium", "Vitamin B6"}));
    fruits.addItem(FoodItem("Orange", 47, 12, 0.9, 0.1, {"Vitamin C", "Fiber"}));
    fruits.addItem(FoodItem("Strawberry", 32, 7.7, 0.7, 0.3, {"Vitamin C", "Manganese"}));
    fruits.addItem(FoodItem("Grapes", 69, 18, 0.7, 0.2, {"Vitamin C", "Vitamin K"}));
    fruits.addItem(FoodItem("Blueberry", 57, 14, 0.7, 0.3, {"Vitamin C", "Vitamin K"}));

    FoodCategory vegetables("Vegetables");
    vegetables.addItem(FoodItem("Carrot", 41, 10, 0.9, 0.2, {"Vitamin A", "Antioxidants"}));
    vegetables.addItem(FoodItem("Broccoli", 55, 11, 3.7, 0.6, {"Vitamin C", "Vitamin K"}));
    vegetables.addItem(FoodItem("Spinach", 23, 3.6, 2.9, 0.4, {"Vitamin A", "Iron"}));
    vegetables.addItem(FoodItem("Bell Pepper", 31, 6, 1, 0.3, {"Vitamin C", "Vitamin A"}));
    vegetables.addItem(FoodItem("Tomato", 18, 3.9, 0.9, 0.2, {"Vitamin C", "Vitamin K"}));
    vegetables.addItem(FoodItem("Cucumber", 16, 3.6, 0.7, 0.1, {"Vitamin K", "Potassium"}));

    FoodCategory proteins("Proteins");
    proteins.addItem(FoodItem("Chicken Breast", 165, 0, 31, 3.6, {"Protein", "Vitamin B6"}));
    proteins.addItem(FoodItem("Egg", 155, 1.1, 13, 11, {"Protein", "Vitamin D"}));
    proteins.addItem(FoodItem("Salmon", 208, 0, 20, 13, {"Omega-3", "Vitamin B12"}));
    proteins.addItem(FoodItem("Beef", 250, 0, 26, 15, {"Protein", "Iron"}));
    proteins.addItem(FoodItem("Tofu", 76, 1.9, 8, 4.8, {"Protein", "Calcium"}));
    proteins.addItem(FoodItem("Lentils", 116, 20, 9, 0.4, {"Protein", "Fiber"}));

    FoodCategory grains("Grains");
    grains.addItem(FoodItem("Rice", 130, 28, 2.7, 0.3, {"Carbohydrates", "Fiber"}));
    grains.addItem(FoodItem("Oats", 389, 66, 16.9, 6.9, {"Fiber", "Protein"}));
    grains.addItem(FoodItem("Quinoa", 120, 21, 4.1, 1.9, {"Protein", "Fiber"}));
    grains.addItem(FoodItem("Barley", 354, 73, 12, 2.3, {"Fiber", "Vitamin B"}));
    grains.addItem(FoodItem("Millet", 119, 23, 3.5, 1, {"Fiber", "Magnesium"}));
    grains.addItem(FoodItem("Buckwheat", 92, 19, 3.4, 0.6, {"Fiber", "Magnesium"}));

    foodCategories.push_back(fruits);
    foodCategories.push_back(vegetables);
    foodCategories.push_back(proteins);
    foodCategories.push_back(grains);
std::unordered_map<std::string, Patient> temp;
    saveDataToFile("food_data.json", foodCategories, temp, CATEGORIES);
}

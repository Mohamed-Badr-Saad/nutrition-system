#include "FoodItem.h"

FoodItem::FoodItem(const string& name, int calories, float carbs, float protein, float fat, const vector<string>& nutrients)
    : name(name), calories(calories), carbs(carbs), protein(protein), fat(fat), nutrients(nutrients) {}

string FoodItem::getName() const {
    return name;
}

int FoodItem::getCalories() const {
    return calories;
}

float FoodItem::getCarbs() const {
    return carbs;
}

float FoodItem::getProtein() const {
    return protein;
}

float FoodItem::getFat() const {
    return fat;
}

vector<string> FoodItem::getNutrients() const {
    return nutrients;
}

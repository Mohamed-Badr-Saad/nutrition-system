#include "FoodCategory.h"

FoodCategory::FoodCategory(const string& name)
    : name(name) {}

string FoodCategory::getName() const {
    return name;
}

void FoodCategory::addItem(const FoodItem& item) {
    items.push_back(item);
}

vector<FoodItem> FoodCategory::getItems() const {
    return items;
}

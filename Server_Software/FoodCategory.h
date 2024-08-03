#ifndef FOODCATEGORY_H
#define FOODCATEGORY_H

#include <string>
#include <vector>
#include "FoodItem.h"

using namespace std;

class FoodCategory {
public:
    FoodCategory(const string& name);

    string getName() const;
    void addItem(const FoodItem& item);
    vector<FoodItem> getItems() const;

private:
    string name;
    vector<FoodItem> items;
};

#endif // FOODCATEGORY_H

#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>
#include <vector>

using namespace std;

class FoodItem {
public:
    FoodItem(const string& name, int calories, float carbs, float protein, float fat, const vector<string>& nutrients);

    string getName() const;
    int getCalories() const;
    float getCarbs() const;
    float getProtein() const;
    float getFat() const;
    vector<string> getNutrients() const;

private:
    string name;
    int calories;
    float carbs;
    float protein;
    float fat;
    vector<string> nutrients;
};

#endif // FOODITEM_H

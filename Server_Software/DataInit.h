#ifndef DATAINIT_H
#define DATAINIT_H

#include "FoodCategory.h"
#include "Patient.h"
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

extern vector<FoodCategory> categories;
extern vector<Patient> patients;

void initializeData(vector<FoodCategory>& foodCategories) ;

#endif // DATAINIT_H

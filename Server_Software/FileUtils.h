#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>
#include <vector>
#include <unordered_map>
#include "FoodCategory.h"
#include "Patient.h"

#define CATEGORIES 1
#define PATIENTS 2

void saveDataToFile(const std::string &filename, const std::vector<FoodCategory> &categories, const std::unordered_map<std::string, Patient> &patients, int savedContent);
void loadDataFromFile(const std::string &filename, std::vector<FoodCategory> &categories, std::unordered_map<std::string, Patient> &patients, int savedContent);

#endif // FILEUTILS_H

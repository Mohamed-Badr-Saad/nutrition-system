#include "Disease.h"



using namespace std;
Disease::Disease(const std::string& name, const std::string& description)
    : name(name), description(description) {}


string Disease::getName() const {
    return name;
}

string Disease::getDescription() const {
    return description;
}

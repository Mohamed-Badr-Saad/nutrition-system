#ifndef DISEASE_H
#define DISEASE_H

#include <string>
using namespace std;
class Disease {
public:
    Disease(const std::string& name, const std::string& description);
    // Add any other members or functions you need here


    string getName() const;
    string getDescription() const;

private:
    string name;
    string description;
};

#endif // DISEASE_H

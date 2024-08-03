#include "Patient.h"

Patient::Patient(){

}


Patient::Patient(const string &userId, const string &name, int age, const string &gender, float height, float weight, const vector<Disease> &diseases, float feedback = -1)
    : userId(userId), name(name), age(age), gender(gender), height(height), weight(weight), diseases(diseases), feedback(feedback) {}

Patient::Patient(const string &userId, const string &name, int age, const string &gender, float height, float weight, const vector<Disease> &diseases)
    : userId(userId), name(name), age(age), gender(gender), height(height), weight(weight), diseases(diseases) {}

string Patient::getUserId() const
{
    return userId;
}

string Patient::getName() const
{
    return name;
}

int Patient::getAge() const
{
    return age;
}

string Patient::getGender() const
{
    return gender;
}

float Patient::getHeight() const
{
    return height;
}

float Patient::getWeight() const
{
    return weight;
}

vector<Disease> Patient::getDiseases() const
{
    return diseases;
}

float Patient::getBMI() const
{
    return calculateBMI();
}

float Patient::getFeedback() const
{
    return feedback;
}




// Setters
void Patient::setUserId(const string &userId) {
    this->userId = userId;
}

void Patient::setName(const string &name) {
    this->name = name;
}

void Patient::setAge(int age) {
    this->age = age;
}

void Patient::setGender(const string &gender) {
    this->gender = gender;
}

void Patient::setHeight(float height) {
    this->height = height;
}

void Patient::setWeight(float weight) {
    this->weight = weight;
}

void Patient::setDiseases(const vector<Disease> &diseases) {
    this->diseases = diseases;
}

void Patient::setFeedback(float score)
{
    this->feedback = score;
}

float Patient::calculateBMI() const
{
    float heightInMeters = height / 100;
    return weight / (heightInMeters * heightInMeters);
}

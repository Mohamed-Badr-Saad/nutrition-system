#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include "Disease.h"

using namespace std;

class Patient
{
public:
    Patient();
    Patient(const string &userId, const string &name, int age, const string &gender, float height, float weight, const vector<Disease> &diseases, float feedback);
    Patient(const string &userId, const string &name, int age, const string &gender, float height, float weight, const vector<Disease> &diseases);
    string getUserId() const;
    string getName() const;
    int getAge() const;
    string getGender() const;
    float getHeight() const;
    float getWeight() const;
    vector<Disease> getDiseases() const;
    float getBMI() const;
    float getFeedback() const;
    void setFeedback(float score);

    // Setters
    void setUserId(const string &userId);
    void setName(const string &name);
    void setAge(int age);
    void setGender(const string &gender);
    void setHeight(float height);
    void setWeight(float weight);
    void setDiseases(const vector<Disease> &diseases);

private:
    string userId;
    string name;
    int age;
    string gender;
    float height; // in cm
    float weight; // in kg
    vector<Disease> diseases;
    float feedback;
    float calculateBMI() const;
};

#endif // PATIENT_H

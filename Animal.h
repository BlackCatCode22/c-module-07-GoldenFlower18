#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

class Animal {
protected:
    std::string uniqueID;
    std::string name;
    std::string birthDate;
    int age;
    std::string sex;
    std::string species;
    std::string color;
    double weight;
    std::string origin;
    std::string arrivalDate;

public:
    Animal() = default;
    
    Animal(int age, std::string sex, std::string species, std::string color, 
           double weight, std::string origin, std::string birthSeason = "");
    
    virtual ~Animal() = default;
    
    // Getter methods
    std::string getUniqueID() const { return uniqueID; }
    std::string getName() const { return name; }
    std::string getBirthDate() const { return birthDate; }
    std::string getSex() const { return sex; }
    std::string getSpecies() const { return species; }
    std::string getColor() const { return color; }
    double getWeight() const { return weight; }
    std::string getOrigin() const { return origin; }
    std::string getArrivalDate() const { return arrivalDate; }
    
    // Setter methods
    void setName(const std::string& newName) { name = newName; }
    void setUniqueID(const std::string& id) { uniqueID = id; }
    void setArrivalDate(const std::string& date) { arrivalDate = date; }
    
    // Generate a birthday based on age and season
    std::string genBirthDay(int age, const std::string& season = "");
    
    // Generate a unique ID for the animal
    virtual std::string genUniqueID(int count) = 0;
    
    // Display animal information
    virtual std::string getInfo() const;
};

#endif // ANIMAL_H
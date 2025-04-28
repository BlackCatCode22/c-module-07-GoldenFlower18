#ifndef DERIVED_ANIMAL_CLASSES_H
#define DERIVED_ANIMAL_CLASSES_H

#include "Animal.h"
#include <sstream>
#include <iomanip>

class Hyena : public Animal {
public:
    Hyena(int age, std::string sex, std::string color, double weight, 
          std::string origin, std::string birthSeason = "")
        : Animal(age, sex, "hyena", color, weight, origin, birthSeason) {}
    
    std::string genUniqueID(int count) override {
        std::stringstream ss;
        ss << "Hy" << std::setw(2) << std::setfill('0') << count;
        return ss.str();
    }
};

class Lion : public Animal {
public:
    Lion(int age, std::string sex, std::string color, double weight, 
         std::string origin, std::string birthSeason = "")
        : Animal(age, sex, "lion", color, weight, origin, birthSeason) {}
    
    std::string genUniqueID(int count) override {
        std::stringstream ss;
        ss << "Li" << std::setw(2) << std::setfill('0') << count;
        return ss.str();
    }
};

class Tiger : public Animal {
public:
    Tiger(int age, std::string sex, std::string color, double weight, 
          std::string origin, std::string birthSeason = "")
        : Animal(age, sex, "tiger", color, weight, origin, birthSeason) {}
    
    std::string genUniqueID(int count) override {
        std::stringstream ss;
        ss << "Ti" << std::setw(2) << std::setfill('0') << count;
        return ss.str();
    }
};

class Bear : public Animal {
public:
    Bear(int age, std::string sex, std::string color, double weight, 
         std::string origin, std::string birthSeason = "")
        : Animal(age, sex, "bear", color, weight, origin, birthSeason) {}
    
    std::string genUniqueID(int count) override {
        std::stringstream ss;
        ss << "Be" << std::setw(2) << std::setfill('0') << count;
        return ss.str();
    }
};

#endif // DERIVED_ANIMAL_CLASSES_H
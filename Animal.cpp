#include "Animal.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <random>

Animal::Animal(int age, std::string sex, std::string species, std::string color, 
               double weight, std::string origin, std::string birthSeason) 
    : age(age), sex(sex), species(species), color(color), 
      weight(weight), origin(origin) {
    
    birthDate = genBirthDay(age, birthSeason);
    
    // Set current date as arrival date
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::stringstream ss;
    ss << std::put_time(now, "%Y-%m-%d");
    arrivalDate = ss.str();
}

std::string Animal::genBirthDay(int age, const std::string& season) {
    // Get current time
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    
    // Calculate birth year
    int birthYear = now->tm_year + 1900 - age;
    
    // Determine month and day based on season
    int month = 1;  // Default to January
    int day = 15;   // Default to middle of month
    
    if (!season.empty()) {
        if (season == "spring") {
            // Spring: March-May
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(3, 5);
            month = distr(gen);
        } else if (season == "summer") {
            // Summer: June-August
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(6, 8);
            month = distr(gen);
        } else if (season == "fall" || season == "autumn") {
            // Fall: September-November
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(9, 11);
            month = distr(gen);
        } else if (season == "winter") {
            // Winter: December-February
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(1, 2);
            month = distr(gen);
            if (distr(gen) % 2 == 0) {
                month = 12;
            }
        }
        
        // Generate a random day within the month
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 28); // Simplifying to avoid month-specific days
        day = distr(gen);
    }
    
    // Format the date as ISO 8601 (YYYY-MM-DD)
    std::stringstream ss;
    ss << birthYear << "-" 
       << std::setw(2) << std::setfill('0') << month << "-" 
       << std::setw(2) << std::setfill('0') << day;
    
    return ss.str();
}

std::string Animal::getInfo() const {
    std::stringstream ss;
    ss << uniqueID << "; " 
       << name << "; "
       << "birth date " << birthDate << "; "
       << color << " color; "
       << sex << "; "
       << weight << " pounds; "
       << "from " << origin << "; "
       << "arrived " << arrivalDate;
    
    return ss.str();
}
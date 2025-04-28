#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "DerivedAnimalClasses.h"
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <memory>

class Zoo {
private:
    std::vector<std::shared_ptr<Animal>> animals;
    std::map<std::string, std::vector<std::shared_ptr<Animal>>> habitats;
    std::map<std::string, std::queue<std::string>> availableNames;
    std::map<std::string, int> speciesCount;
    
    // Parse animal description
    void parseAnimalDescription(const std::string& description);
    
    // Load animal names from file
    void loadAnimalNames(const std::string& filename);
    
    // Get next available name for a species
    std::string getNextAvailableName(const std::string& species);
    
public:
    Zoo();
    
    // Load animals from file
    void loadAnimals(const std::string& filename);
    
    // Organize animals into habitats
    void organizeHabitats();
    
    // Generate zoo population report
    void generateReport(const std::string& filename);
};

#endif // ZOO_H
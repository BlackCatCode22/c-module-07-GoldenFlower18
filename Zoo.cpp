#include "Zoo.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>
#include <stdexcept>

Zoo::Zoo() {
    // Initialize species counts
    speciesCount["hyena"] = 0;
    speciesCount["lion"] = 0;
    speciesCount["tiger"] = 0;
    speciesCount["bear"] = 0;
}

void Zoo::loadAnimalNames(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Could not open animal names file: " + filename);
    }
    
    std::string line;
    std::string currentSpecies;
    
    while (std::getline(file, line)) {
        // Check if line indicates a species
        if (line == "Hyena:") {
            currentSpecies = "hyena";
        } else if (line == "Lion:") {
            currentSpecies = "lion";
        } else if (line == "Tiger:") {
            currentSpecies = "tiger";
        } else if (line == "Bear:") {
            currentSpecies = "bear";
        } else if (!line.empty() && !currentSpecies.empty()) {
            // It's a name - add to the queue
            availableNames[currentSpecies].push(line);
        }
    }
}

std::string Zoo::getNextAvailableName(const std::string& species) {
    if (availableNames[species].empty()) {
        return "Unknown";
    }
    
    std::string name = availableNames[species].front();
    availableNames[species].pop();
    return name;
}

void Zoo::parseAnimalDescription(const std::string& description) {
    // Use regex to extract information
    std::regex agePattern("(\\d+)\\s+year\\s+old");
    std::regex sexPattern("(female|male)");
    std::regex speciesPattern("(hyena|lion|tiger|bear)");
    std::regex seasonPattern("born\\s+in\\s+(spring|summer|fall|autumn|winter)");
    std::regex colorPattern("(\\w+)\\s+color");
    std::regex weightPattern("(\\d+)\\s+pounds");
    std::regex originPattern("from\\s+(.+)$");
    
    std::smatch match;
    
    // Extract age
    int age = 0;
    if (std::regex_search(description, match, agePattern)) {
        age = std::stoi(match[1]);
    }
    
    // Extract sex
    std::string sex;
    if (std::regex_search(description, match, sexPattern)) {
        sex = match[1];
    }
    
    // Extract species
    std::string species;
    if (std::regex_search(description, match, speciesPattern)) {
        species = match[1];
    }
    
    // Extract birth season if available
    std::string birthSeason;
    if (std::regex_search(description, match, seasonPattern)) {
        birthSeason = match[1];
    }
    
    // Extract color
    std::string color;
    if (std::regex_search(description, match, colorPattern)) {
        color = match[1];
    }
    
    // Extract weight
    double weight = 0.0;
    if (std::regex_search(description, match, weightPattern)) {
        weight = std::stod(match[1]);
    }
    
    // Extract origin
    std::string origin;
    if (std::regex_search(description, match, originPattern)) {
        origin = match[1];
    }
    
    // Create appropriate animal based on species
    std::shared_ptr<Animal> animal;
    
    if (species == "hyena") {
        animal = std::make_shared<Hyena>(age, sex, color, weight, origin, birthSeason);
        speciesCount["hyena"]++;
        animal->setUniqueID(animal->genUniqueID(speciesCount["hyena"]));
    } else if (species == "lion") {
        animal = std::make_shared<Lion>(age, sex, color, weight, origin, birthSeason);
        speciesCount["lion"]++;
        animal->setUniqueID(animal->genUniqueID(speciesCount["lion"]));
    } else if (species == "tiger") {
        animal = std::make_shared<Tiger>(age, sex, color, weight, origin, birthSeason);
        speciesCount["tiger"]++;
        animal->setUniqueID(animal->genUniqueID(speciesCount["tiger"]));
    } else if (species == "bear") {
        animal = std::make_shared<Bear>(age, sex, color, weight, origin, birthSeason);
        speciesCount["bear"]++;
        animal->setUniqueID(animal->genUniqueID(speciesCount["bear"]));
    } else {
        throw std::runtime_error("Unknown animal species: " + species);
    }
    
    // Set the animal's name
    animal->setName(getNextAvailableName(species));
    
    // Add to the animals vector
    animals.push_back(animal);
}

void Zoo::loadAnimals(const std::string& filename) {
    // First load animal names
    loadAnimalNames("animalNames.txt");
    
    // Then load animal descriptions
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Could not open animal file: " + filename);
    }
    
    std::string line;
    
    while (std::getline(file, line)) {
        if (!line.empty()) {
            parseAnimalDescription(line);
        }
    }
}

void Zoo::organizeHabitats() {
    // Clear existing habitats
    habitats.clear();
    
    // Place each animal in its appropriate habitat
    for (const auto& animal : animals) {
        std::string species = animal->getSpecies();
        habitats[species].push_back(animal);
    }
}

void Zoo::generateReport(const std::string& filename) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Could not open output file: " + filename);
    }
    
    // Report all habitats
    file << "Zookeeper's Report - Zoo Population\n\n";
    
    // Hyena habitat
    file << "Hyena Habitat:\n";
    for (const auto& animal : habitats["hyena"]) {
        file << "* " << animal->getInfo() << "\n";
    }
    file << "\n";
    
    // Lion habitat
    file << "Lion Habitat:\n";
    for (const auto& animal : habitats["lion"]) {
        file << "* " << animal->getInfo() << "\n";
    }
    file << "\n";
    
    // Tiger habitat
    file << "Tiger Habitat:\n";
    for (const auto& animal : habitats["tiger"]) {
        file << "* " << animal->getInfo() << "\n";
    }
    file << "\n";
    
    // Bear habitat
    file << "Bear Habitat:\n";
    for (const auto& animal : habitats["bear"]) {
        file << "* " << animal->getInfo() << "\n";
    }
    
    file.close();
    
    std::cout << "Report generated successfully: " << filename << std::endl;
}
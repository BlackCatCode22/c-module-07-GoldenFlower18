#include "Zoo.h"
#include <iostream>
#include <stdexcept>

int main() {
    std::cout << "Zookeeper's Challenge - Zoo Management System\n";
    std::cout << "---------------------------------------------\n\n";
    
    try {
        // Create a zoo
        Zoo zoo;
        
        // Load animals from file
        std::cout << "Loading animals from arrivingAnimals.txt...\n";
        zoo.loadAnimals("arrivingAnimals.txt");
        
        // Organize animals into habitats
        std::cout << "Organizing animals into habitats...\n";
        zoo.organizeHabitats();
        
        // Generate report
        std::cout << "Generating zoo population report...\n";
        zoo.generateReport("zooPopulation.txt");
        
        std::cout << "\nZoo management tasks completed successfully!\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
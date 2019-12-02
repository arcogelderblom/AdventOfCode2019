#include "FuelRequirementCalculator.hpp"
#include "FileLoader.hpp"

#include <iostream>
#include <vector>
#include <string>

int main() {
    FileLoader fileLoader;
    FuelRequirementCalculator calculator;
    std::vector<std::string> lines = fileLoader.getLinesFromFile("01-december/input.txt");
    std::vector<int> masses;
    for (std::string line : lines) {
        masses.push_back(std::stoi(line));
    }

    std::cout << "The result for puzzle one is: " << calculator.getSumOfFuelRequirements(masses, 1) << std::endl;
    std::cout << "The result for puzzle two is: " << calculator.getSumOfFuelRequirements(masses, 2) << std::endl;
    return 0;
}
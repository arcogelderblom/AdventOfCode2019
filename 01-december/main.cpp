#include "FuelRequirementCalculator.hpp"
#include "../common/FileLoader.hpp"

#include <iostream>
#include <vector>
#include <string>

int main() {
    FileLoader fileLoader;
    FuelRequirementCalculator calculator;
    std::vector<std::string> lines = fileLoader.getLinesFromFile("/Users/Arco/Documents/Eigen documenten/Projecten/AdventOfCode2019/01-december/input.txt");
    std::vector<int> masses;
    for (std::string line : lines) {
        masses.push_back(std::stoi(line));
    }

    std::cout << "The result for puzzle one is: " << calculator.getSumOfFuelRequirements(masses) << std::endl;
    return 0;
}
#include "FileLoader.hpp"

#include "NanoFactory.hpp"
#include <iostream>

int main() {
    FileLoader fileLoader;
    std::vector<std::string> chemicalReactions = fileLoader.getLinesFromFile("14-december/input.txt");
    
    NanoFactory nanofactory;
    std::vector<Reaction> parsed = nanofactory.parse(chemicalReactions);
    nanofactory.calculateMaterialsNeeded(parsed, "FUEL", 1);
    std::cout << "The result for puzzle one is: " << nanofactory.getAmountOfOre(parsed) << std::endl;
    std::cout << "The result for puzzle two is: " << nanofactory.getFuel(parsed, 1000000000000) << std::endl;
}
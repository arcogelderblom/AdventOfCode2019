#include "FileLoader.hpp"

#include "MoonPositionCalculator.hpp"

#include <iostream>

int main () {
    FileLoader fileLoader;
    std::vector<std::string> moonStrings = fileLoader.getLinesFromFile("12-december/input.txt");

    MoonPositionCalculator moonPositionCalculator;
    std::vector<Moon> moons = moonPositionCalculator.parse(moonStrings);
    int steps = 1000;
    moonPositionCalculator.calculate(moons, steps);

    std::cout << "The result for puzzle one is: " << moonPositionCalculator.getTotalEnergy(moons) << std::endl;
    moons = moonPositionCalculator.parse(moonStrings); // reset
    std::cout << "The result for puzzle two is: " << moonPositionCalculator.getAmountOfStepsRecurringState(moons) << std::endl;

    return 0;
}
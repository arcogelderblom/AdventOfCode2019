#include "FuelRequirementCalculator.hpp"
#include <iostream>

int FuelRequirementCalculator::getSumOfFuelRequirements(const std::vector<int> masses, int puzzleNumber) {
    int result = 0;
    for (int mass : masses) {
        if (puzzleNumber == 1) {
            result += getFuelRequirementPuzzleOne(mass);
        } else {
            result += getFuelRequirementPuzzleTwo(mass);
        }
    }
    return result;
}

int FuelRequirementCalculator::getFuelRequirementPuzzleOne(const int mass) {
    return (mass/3)-2;
}

int FuelRequirementCalculator::getFuelRequirementPuzzleTwo(const int mass) {
    int result = (mass/3) - 2;
    if (result <= 0) {
        return 0;
    } else {
        return result + getFuelRequirementPuzzleTwo(result);
    }
}
    
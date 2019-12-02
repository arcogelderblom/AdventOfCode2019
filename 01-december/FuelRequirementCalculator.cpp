#include "FuelRequirementCalculator.hpp"
#include <iostream>

const int FuelRequirementCalculator::getSumOfFuelRequirements(const std::vector<int> masses) {
    int result = 0;
    for(int mass : masses) {
        result += getFuelRequirement(mass);
    }
    return result;
}

const int FuelRequirementCalculator::getFuelRequirement(const int mass) {
    return (mass/3)-2;
}
    
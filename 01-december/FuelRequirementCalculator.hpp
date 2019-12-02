#pragma once

#include <vector>

class FuelRequirementCalculator {
    public:
        const int getSumOfFuelRequirements(const std::vector<int> masses);
        const int getFuelRequirement(const int mass);
};
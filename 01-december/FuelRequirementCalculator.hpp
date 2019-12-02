#pragma once

#include <vector>

class FuelRequirementCalculator {
    public:
        int getSumOfFuelRequirements(const std::vector<int> masses, int puzzleNumber);
        int getFuelRequirementPuzzleOne(const int mass);
        int getFuelRequirementPuzzleTwo(const int mass);
};
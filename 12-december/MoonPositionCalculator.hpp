#pragma once

#include <vector>
#include <tuple>
#include <string>

struct Moon {
    int x;
    int y;
    int z;
    std::tuple<int, int, int> velocity; // xyz velocity
};

class MoonPositionCalculator {
    private:
        void calculateVelocity(Moon & moon1, Moon & moon2);
    public:
        void calculate(std::vector<Moon> & moons, int steps);
        int getTotalEnergy(std::vector<Moon> moons);
        long getAmountOfStepsRecurringState(std::vector<Moon> moons);
        std::vector<Moon> parse(std::vector<std::string> moonStrings);
};
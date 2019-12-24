#include "MoonPositionCalculator.hpp"

#include <iostream>

void MoonPositionCalculator::calculateVelocity(Moon & moon1, Moon & moon2) {
    if (moon1.x > moon2.x) {
        std::get<0>(moon1.velocity) -= 1;
        std::get<0>(moon2.velocity) += 1;
    } else if (moon1.x < moon2.x) {
        std::get<0>(moon1.velocity) += 1;
        std::get<0>(moon2.velocity) -= 1;
    } 
    
     if (moon1.y > moon2.y) {
        std::get<1>(moon1.velocity) -= 1;
        std::get<1>(moon2.velocity) += 1;
    } else if (moon1.y < moon2.y) {
        std::get<1>(moon1.velocity) += 1;
        std::get<1>(moon2.velocity) -= 1;
    } 
    
    if (moon1.z > moon2.z) {
        std::get<2>(moon1.velocity) -= 1;
        std::get<2>(moon2.velocity) += 1;
    } else if (moon1.z < moon2.z) {
        std::get<2>(moon1.velocity) += 1;
        std::get<2>(moon2.velocity) -= 1;
    } 
}

void MoonPositionCalculator::calculate(std::vector<Moon> & moons, int steps) {
    for (int i = 0; i < steps; i++) {
        for (int startIndex = 0; startIndex < moons.size() - 1; startIndex++) {
            for (int index = startIndex + 1; index < moons.size(); index++) {
                calculateVelocity(moons[startIndex], moons[index]);
            }
        }
        for (Moon & moon : moons) {
            moon.x += std::get<0>(moon.velocity);
            moon.y += std::get<1>(moon.velocity);
            moon.z += std::get<2>(moon.velocity);
        }
    }
}

int MoonPositionCalculator::getTotalEnergy(std::vector<Moon> moons) {
    int energy = 0;
    for (const Moon & moon : moons) {
        int potential = std::abs(moon.x) + std::abs(moon.y) + std::abs(moon.z);
        int kinetic = std::abs(std::get<0>(moon.velocity)) + std::abs(std::get<1>(moon.velocity)) + std::abs(std::get<2>(moon.velocity));
        int totalEnergyMoon = potential * kinetic;
        energy += totalEnergyMoon;
    }
    return energy;
}

long MoonPositionCalculator::getAmountOfStepsRecurringState(std::vector<Moon> moons) {
    long steps = 0;
    int curEnergy = -1;
    while (curEnergy != 0) {
        calculate(moons, 1);
        curEnergy = getTotalEnergy(moons);
        steps += 1;
        if (steps % 1000000 == 0) {
            std::cout << "Current step = " << steps << std::endl;
        }
    }

    return steps*2;
}

std::vector<Moon> MoonPositionCalculator::parse(std::vector<std::string> moonStrings) {
    std::vector<Moon> result;
    for (const std::string & moonString : moonStrings) {
        Moon moon;
        moon.x = std::stoi(moonString.substr(moonString.find("<x=") + strlen("<x="), moonString.find(", y=") - (moonString.find("<x=") + strlen("<x="))));
        moon.y = std::stoi(moonString.substr(moonString.find(", y=") + strlen(", y="), moonString.find(", z=") - (moonString.find(", y=") + strlen(", y="))));
        moon.z = std::stoi(moonString.substr(moonString.find(", z=") + strlen(", z="), moonString.find(">") - (moonString.find(", z=") + strlen(", z="))));
        moon.velocity = std::make_tuple(0, 0, 0); // starts with zero velocity in any direction
        result.push_back(moon);
    }
    return result;
}

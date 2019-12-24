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
    // std::cout << "Current step: " << 0 << std::endl;
    // for (const Moon & moon : moons) {
    //     std::cout << "<x= " << moon.x << ", y= " << moon.y << ", z= " << moon.z << "> <x= " << std::get<0>(moon.velocity) << ", y= " << std::get<1>(moon.velocity) << ", z= " << std::get<2>(moon.velocity) << ">" << std::endl;
    // }  
    for (int i = 1; i <= steps; i++) {
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

        // std::cout << "Current step: " << i << std::endl;
        // for (const Moon & moon : moons) {
        //     std::cout << "<x= " << moon.x << ", y= " << moon.y << ", z= " << moon.z << "> <x= " << std::get<0>(moon.velocity) << ", y= " << std::get<1>(moon.velocity) << ", z= " << std::get<2>(moon.velocity) << ">" << std::endl;
        // }  
        // std::cout << std::endl;
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
    std::vector<Moon> startState = moons;
    bool xNumFound = false;
    bool yNumFound = false;
    bool zNumFound = false;
    
    long stepsX = 0;
    long stepsY = 0;
    long stepsZ = 0;

    long steps = 0;
    while (!xNumFound || !yNumFound || !zNumFound) {
        calculate(moons, 1); // calculate one step at a time
        steps += 1;

        int xAxisZero = 0;
        int yAxisZero = 0;
        int zAxisZero = 0;
        int sameX = 0;
        int sameY = 0;
        int sameZ = 0;
        for (Moon moon : moons) {
            if (std::get<0>(moon.velocity) == 0 && !xNumFound) {
                xAxisZero += 1;
            }
            if (std::get<1>(moon.velocity) == 0 && !yNumFound) {
                yAxisZero += 1;
            }
            if (std::get<2>(moon.velocity) == 0 && !zNumFound) {
                zAxisZero += 1;
            }

            if (xAxisZero == 4) {
                int i = 0;
                for (Moon _moon : moons) {
                    if (_moon.x == startState[i].x) {
                        sameX += 1;
                    }
                    else {
                        break;
                    }
                    i++;
                }
            }
            if (yAxisZero == 4) {
                int i = 0;
                for (Moon _moon : moons) {
                    if (_moon.y == startState[i].y) {
                        sameY += 1;
                    }
                    else {
                        break;
                    }
                    i++;
                }
            }
            if (zAxisZero == 4) {
                int i = 0;
                for (Moon _moon : moons) {
                    if (_moon.z == startState[i].z) {
                        sameZ += 1;
                    }
                    else {
                        break;
                    }
                    i++;
                }
            }

            if (sameX == 4 && !xNumFound) {
                xNumFound = true;
                stepsX = steps;
            }
            if (sameY == 4 && !yNumFound) {
                yNumFound = true;
                stepsY = steps;
            }
            if (sameZ == 4 && !zNumFound) {
                zNumFound = true;
                stepsZ = steps;
            }
        }
    }

    if (stepsX > stepsY && stepsX > stepsZ) {
        for (long totalSteps = stepsX;;totalSteps+=stepsX) {
            if (totalSteps % stepsX == 0 && totalSteps % stepsY == 0 && totalSteps % stepsZ == 0) {
                return totalSteps;
            }
        }
    }
    if (stepsY > stepsX && stepsY > stepsZ) {
        for (long totalSteps = stepsY;;totalSteps+=stepsY) {
            if (totalSteps % stepsX == 0 && totalSteps % stepsY == 0 && totalSteps % stepsZ == 0) {
                return totalSteps;
            }
        }
    }
    if (stepsZ > stepsX && stepsZ > stepsY) {
        for (long totalSteps = stepsZ;;totalSteps+=stepsZ) {
            if (totalSteps % stepsX == 0 && totalSteps % stepsY == 0 && totalSteps % stepsZ == 0) {
                return totalSteps;
            }
        }
    }

    return 0;
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

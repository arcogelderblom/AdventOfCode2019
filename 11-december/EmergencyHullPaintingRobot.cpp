#include "EmergencyHullPaintingRobot.hpp"

#include "IntcodeComputer.hpp"
#include <iostream>

std::vector<std::pair<Coordinate, std::string> > EmergencyHullPaintingRobot::getCoordinatesToColor(std::vector<long> program, int puzzleNum) {
    std::vector<std::pair<Coordinate, std::string> > result;

    IntcodeComputer intcodeComputer(program);
    Coordinate currentLocation = {0,0};
    std::vector<int> input;
    if (puzzleNum == 1) {
        input.push_back(0); // robots starts at black/white position depending on puzzle 1/2
    } else if (puzzleNum == 2) {
        input.push_back(1); // robots starts at black/white position depending on puzzle 1/2
    } 
    while(1) {
        Coordinate oldPlace = currentLocation;
        int output = intcodeComputer.getOutputUsingInput(input);

        if (output == -1) { 
            break;
        } else if (output == 0) {
            bool coordinateFound = false;
            for (std::pair<Coordinate, std::string> & entry : result) {
                if (entry.first.x == currentLocation.x && entry.first.y == currentLocation.y) {
                    coordinateFound = true;
                    entry.second = ".";
                }
            }
            if (coordinateFound == false) {
                result.push_back(std::make_pair(currentLocation, std::string(".")));
            }
        } else if (output == 1) {
            bool coordinateFound = false;
            for (std::pair<Coordinate, std::string> & entry : result) {
                if (entry.first.x == currentLocation.x && entry.first.y == currentLocation.y) {
                    coordinateFound = true;
                    entry.second = "#";
                }
            }
            if (!coordinateFound) {
                result.push_back(std::make_pair(currentLocation, std::string("#")));
            }
        }

        output = intcodeComputer.getOutputUsingInput(input);

        // check how the robot should move
        if (output == -1) { 
            break;
        } else if (output == 0) {
            currentAngle -= 90;
        } else if (output == 1) {
            currentAngle += 90;
        }

        // correct angle
        if (currentAngle == -90) {
            currentAngle = 270;
        } else if (currentAngle == 360) {
            currentAngle = 0;
        }

        // move robot
        if (currentAngle == 0) {
            currentLocation.y += 1;
        } else if (currentAngle == 90) {
            currentLocation.x += 1;
        } else if (currentAngle == 180) {
            currentLocation.y -= 1;
        } else if (currentAngle == 270) {
            currentLocation.x -= 1;
        }
        
        // get color of new location
        int color = 0;
        for (std::pair<Coordinate, std::string> entry : result) {
            if (entry.first.x == currentLocation.x && entry.first.y == currentLocation.y) {
                if (entry.second == "#") {
                    color = 1;
                } else if (entry.second == ".") {
                    color = 0;
                }
            }
        }

        input.push_back(color);
    }
    return result;
}

void EmergencyHullPaintingRobot::printCoordinates(std::vector<std::pair<Coordinate, std::string> > coordinatesWithValue) {
    int lowestX = 0;
    int lowestY = 0;
    int highestX = 0;
    int highestY = 0;
    for (const std::pair<Coordinate, std::string> & entry : coordinatesWithValue) {
        if (entry.first.x < lowestX) {
            lowestX = entry.first.x;
        }
        if (entry.first.y < lowestY) {
            lowestY = entry.first.y;
        }
        if (entry.first.x > highestX) {
            highestX = entry.first.x;
        }
        if (entry.first.y > highestY) {
            highestY = entry.first.y;
        }
    }

    for (int y = highestY; y >= lowestY; y--) {
        for (int x = lowestX; x <= highestX; x++) {
            bool found = false;
            for (const std::pair<Coordinate, std::string> & entry : coordinatesWithValue) {
                if (entry.first.x == x && entry.first.y == y) {
                    found = true;
                    std::cout << entry.second;
                }
            }
            if (!found) {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

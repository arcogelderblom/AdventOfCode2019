#include <gtest/gtest.h>

#include "EmergencyHullPaintingRobot.hpp"

TEST(DecemberElevenTest, PuzzleOneTestOne) {
    int currentAngle = 0;
    std::vector<std::pair<Coordinate, std::string> > result;
    std::vector<int> outputs = {1,0,0,0,1,0,1,0,0,1,1,0,1,0};
    // IntcodeComputer intcodeComputer(program);
    
    Coordinate currentLocation = {0,0};
    std::vector<int> input;
    int q = 0;
    input.push_back(0);
    for (auto it = outputs.begin(); it != outputs.end(); it++) {
        Coordinate oldPlace = currentLocation;
        int output = *it;

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

        output = *++it;
        if (output == -1) { 
            break;
        } else if (output == 0) {
            currentAngle -= 90;
        } else if (output == 1) {
            currentAngle += 90;
        }
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
    EmergencyHullPaintingRobot emergencyHullPaintingRobot;
    emergencyHullPaintingRobot.printCoordinates(result);
    ASSERT_EQ(result.size(), 6);
}
#include "FileLoader.hpp"

#include "EmergencyHullPaintingRobot.hpp"
#include <iostream>

int main() {
    FileLoader fileLoader;
    std::vector<std::string> codes = fileLoader.getCommaSeparatedVectorFromFile("11-december/input.txt");
    
    std::vector<long> program;
    for (std::string code : codes) {
        program.push_back(std::stol(code));
    }
    
    EmergencyHullPaintingRobot emergencyHullPaintingRobot;
    auto coordinatesToColor = emergencyHullPaintingRobot.getCoordinatesToColor(program, 1);
    std::cout << "The result for puzzle one is: " << coordinatesToColor.size() << std::endl;
    coordinatesToColor = emergencyHullPaintingRobot.getCoordinatesToColor(program, 2);
    std::cout << "The result for puzzle two is: " << std::endl;
    emergencyHullPaintingRobot.printCoordinates(coordinatesToColor);
}
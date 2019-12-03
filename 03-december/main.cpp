#include "FileLoader.hpp"
#include "WirePath.hpp"
#include "ManhattanDistanceCalculator.hpp"

#include <iostream>
#include <vector>
#include <string>

int main() {
    FileLoader fileLoader;
    std::vector<std::string> linesFromFile = fileLoader.getLinesFromFile("03-december/input.txt");
    std::vector< std::vector<std::string> > lines;
    for (std::string line: linesFromFile) {
        std::vector<std::string> tmpLines;
        while (!line.empty()) {
            std::string tmp = line.substr(0, line.find(","));
            tmpLines.push_back(tmp);
            if (line.find(",") == std::string::npos) {
                break;
            }
            line = line.substr(line.find(",")+1);
        }  
        lines.push_back(tmpLines);
    }

    std::vector<WirePath> wirePaths;
    for (std::vector<std::string> wireInstructions : lines) {
        wirePaths.push_back(WirePath(wireInstructions));
    }

    ManhattanDistanceCalculator calculator;

    std::cout << "The result for puzzle one is: " << calculator.getManhattanShortestDistance(wirePaths) << std::endl;
    
    return 0;
}
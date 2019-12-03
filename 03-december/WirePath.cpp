#include "WirePath.hpp"

WirePath::WirePath(std::vector<std::string> instructions) :
    instructions(instructions)
{}

std::vector< std::pair<int, int> > WirePath::calculatePath() {
    std::vector< std::pair<int, int> > result;
    std::pair<int, int> currentPoint(0, 0);
    for (std::string instruction : instructions) {
        if (instruction[0] == 'U') {
            for (int i = 0; i < std::stoi(instruction.substr(1)); i++) {
                currentPoint.first += 1;
                result.push_back(currentPoint);
            }
        }
        if (instruction[0] == 'D') {
            for (int i = 0; i < std::stoi(instruction.substr(1)); i++) {
                currentPoint.first -= 1;
                result.push_back(currentPoint);
            }
        }
        if (instruction[0] == 'L') {
            for (int i = 0; i < std::stoi(instruction.substr(1)); i++) {
                currentPoint.second -= 1;
                result.push_back(currentPoint);
            }
        }
        if (instruction[0] == 'R') {
            for (int i = 0; i < std::stoi(instruction.substr(1)); i++) {
                currentPoint.second += 1;
                result.push_back(currentPoint);
            }
        }
    }
    return result;
}
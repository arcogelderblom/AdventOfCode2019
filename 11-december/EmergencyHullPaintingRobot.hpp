#pragma once

#include <vector>
#include <string>

struct Coordinate {
    int x;
    int y;
};

class EmergencyHullPaintingRobot {
    private:
        int currentAngle = 0;
    public:
        std::vector<std::pair<Coordinate, std::string> > getCoordinatesToColor(std::vector<long> program, int puzzleNum);
        void printCoordinates(std::vector<std::pair<Coordinate, std::string> > coordinatesWithValue);
};
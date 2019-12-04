#pragma once

#include "WirePath.hpp"
#include <vector>

class ManhattanDistanceCalculator {
    private:
        std::vector<WirePath> wirePaths;
        std::vector< std::vector< std::pair<int,int> > > paths;

        std::vector< std::pair<int, int> > calculateIntersections();
    public:
        ManhattanDistanceCalculator(std::vector<WirePath> wirePaths);
        int getManhattanShortestDistance();
        int getFewestSteps();
};
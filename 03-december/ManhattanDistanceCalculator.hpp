#pragma once

#include "WirePath.hpp"
#include <vector>

class ManhattanDistanceCalculator {
    public:
        int getManhattanShortestDistance(std::vector<WirePath> wirePaths);
};
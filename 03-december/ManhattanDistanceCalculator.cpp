#include "ManhattanDistanceCalculator.hpp"
#include <cmath>

int ManhattanDistanceCalculator::getManhattanShortestDistance(std::vector<WirePath> wirePaths) {
    std::vector< std::vector< std::pair<int,int> > > paths;
    int i = 0;
    for (WirePath wire : wirePaths) {
        i++;
        paths.push_back(wire.calculatePath());
    }

    // get all cross sections
    std::vector<std::pair<int,int> > intersections;
    int amountOfWirePaths = paths.size();
    for (std::pair<int, int> coordinates : paths[0]) {
        for (int i = 1; i < amountOfWirePaths; i++) {
            int amountOfIntersections = 1;
            for (std::pair<int, int> coordinates2 : paths[i]) {
                if (coordinates == coordinates2) {
                    amountOfIntersections += 1;
                    break;
                }
            }
            if (amountOfIntersections == amountOfWirePaths) {
                intersections.push_back(coordinates);
            }
        }
    }
    
    int lowestDistance = std::abs(intersections[0].first) + std::abs(intersections[0].second);
    for (std::pair<int, int> intersection : intersections) {
        int distance = std::abs(intersection.first) + std::abs(intersection.second);
        if (distance < lowestDistance) {
            lowestDistance = distance;
        }
    }
    return lowestDistance;
}
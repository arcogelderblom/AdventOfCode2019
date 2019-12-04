#include "ManhattanDistanceCalculator.hpp"
#include <cmath>
#include <iterator>

ManhattanDistanceCalculator::ManhattanDistanceCalculator(std::vector<WirePath> wirePaths) :
    wirePaths(wirePaths)
{
    int i = 0;
    for (WirePath wire : wirePaths) {
        i++;
        paths.push_back(wire.calculatePath());
    }
}

int ManhattanDistanceCalculator::getManhattanShortestDistance() { 
    std::vector<std::pair<int,int> > intersections = calculateIntersections();

    int lowestDistance = std::abs(intersections[0].first) + std::abs(intersections[0].second);
    for (std::pair<int, int> intersection : intersections) {
        int distance = std::abs(intersection.first) + std::abs(intersection.second);
        if (distance < lowestDistance) {
            lowestDistance = distance;
        }
    }
    return lowestDistance;
}

int ManhattanDistanceCalculator::getFewestSteps() {
    std::vector<std::pair<int,int> > intersections = calculateIntersections();

    int fewestSteps = 0;
    for (int i = 0; i < paths.size(); i++) {
        fewestSteps += std::distance(paths[i].begin(), std::find(paths[i].begin(), paths[i].end(), intersections[0]))+1; // distance counts between first and last, so +1 to include last
    }
    for (int i = 1; i < intersections.size(); i++) {
        int distance = 0;
        for (int j = 0; j < paths.size(); j++) {
            distance += std::distance(paths[j].begin(), std::find(paths[j].begin(), paths[j].end(), intersections[i])+1); // distance counts between first and last, so +1 to include last
        }
        if (distance < fewestSteps) {
            fewestSteps = distance;
        }
    }
    return fewestSteps;
}

std::vector< std::pair<int, int> > ManhattanDistanceCalculator::calculateIntersections() {
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
    return intersections;
}
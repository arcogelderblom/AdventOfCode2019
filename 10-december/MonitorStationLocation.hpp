#pragma once

#include <vector>
#include <map>
#include <string>

struct Coordinate {
    int x;
    int y;

    bool operator==( const Coordinate & coordinate ) const {
        return x == coordinate.x && y == coordinate.y;
    }

    bool operator<( const Coordinate & coordinate ) const {
        return x < coordinate.x || (x == coordinate.x && (y < coordinate.y));
    }
};

class MonitorStationLocation {
    private:
        std::map<Coordinate, std::vector<Coordinate> > visibleAsteroidsPerAsteroid;
        float calculateAngle(Coordinate self, Coordinate other);
        std::vector<Coordinate> getAsteroids(std::vector<std::string> map);
        std::map<Coordinate, std::vector<Coordinate> > getVisibleAstroidsPerAsteroid(std::vector<std::string> map);
    public:
        std::pair<Coordinate, int> getBestLocation(std::vector<std::string> map);
        Coordinate getVaporizedCoordinate(Coordinate monitoringStationCoordinate, int number);
};
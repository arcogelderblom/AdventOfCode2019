#include "MonitorStationLocation.hpp"

#include <math.h>
#include <iostream>

#define PI 3.14159265359

float MonitorStationLocation::calculateAngle(Coordinate self, Coordinate other) {
    float x = std::abs(other.x - self.x);
    float y = std::abs(other.y - self.y);
    if (other.x > self.x && other.y < self.y) { // right up
        return atan(x/y) * (180/PI);
    }
    else if (other.x > self.x && other.y > self.y) { // right down
        return 90 + (atan(y/x) * (180/PI));
    }
    else if (other.x < self.x && other.y > self.y) { // left down
        return 180 + (atan(x/y) * (180/PI));
    }
    else if (other.x < self.x && other.y < self.y) { // left up
        return 270 + (atan(y/x) * (180/PI));
    }
    else if (other.x == self.x && other.y < self.y) { // same line up
        return 0;
    }
    else if (other.x > self.x && other.y == self.y) { // same line right
        return 90;
    }
    else if (other.x == self.x && other.y > self.y) { // same line down
        return 180;
    }
    else if (other.x < self.x && other.y == self.y) { // same line left
        return 270;
    }
    return 0;
}

std::vector<Coordinate> MonitorStationLocation::getAsteroids(std::vector<std::string> map) {
    std::vector<Coordinate> asteroids;
    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x <= map[y].size(); x++) {
            if (map[y][x] == '#') {
                Coordinate coordinate = {x,y};
                asteroids.push_back(coordinate);
            }  
        }
    }
    return asteroids;
}

std::map<Coordinate, std::vector<Coordinate> > MonitorStationLocation::getVisibleAstroidsPerAsteroid(std::vector<std::string> map) {
    std::vector<Coordinate> asteroids = getAsteroids(map);
    for (Coordinate asteroid : asteroids) {
        std::vector<Coordinate> visibleAsteroids;
        std::map<float, std::pair<Coordinate, int> > mapAngleCoordinateDistance;
        for (Coordinate checkVisibleAsteroid : asteroids) {
            
            if (!(checkVisibleAsteroid.x == asteroid.x && checkVisibleAsteroid.y == asteroid.y)) { // discard itself
                int distance = std::abs(checkVisibleAsteroid.y - asteroid.y) + std::abs(checkVisibleAsteroid.x - asteroid.x);
                float angle = calculateAngle(asteroid, checkVisibleAsteroid);
                if (mapAngleCoordinateDistance.find(angle) == mapAngleCoordinateDistance.end()) {
                    mapAngleCoordinateDistance[angle] = std::make_pair(checkVisibleAsteroid, distance);
                } else {
                    if (distance < mapAngleCoordinateDistance[angle].second) {
                        mapAngleCoordinateDistance[angle] = std::make_pair(checkVisibleAsteroid, distance);
                    }
                }
            }
        }
        for (auto entry : mapAngleCoordinateDistance) {
            visibleAsteroidsPerAsteroid[asteroid].push_back(entry.second.first);
        }
    }
    
    return visibleAsteroidsPerAsteroid;
}

std::pair<Coordinate, int> MonitorStationLocation::getBestLocation(std::vector<std::string> map) {
    Coordinate coordinate = {0,0};
    std::map<Coordinate, std::vector<Coordinate> > visibleAsteroidsPerAsteroid = getVisibleAstroidsPerAsteroid(map);
    int maxVisibleAsteroids = 0;
    
    for (auto entry : visibleAsteroidsPerAsteroid) {
        if (entry.second.size() > maxVisibleAsteroids) {
            coordinate = entry.first;
            maxVisibleAsteroids = entry.second.size();
        }
    }
    
    return std::make_pair(coordinate, maxVisibleAsteroids);
}

Coordinate MonitorStationLocation::getVaporizedCoordinate(Coordinate monitoringStationCoordinate, int number) {
    Coordinate result = {0,0};
    int vaporizedAsteroids = 0;
    std::vector<float> allAngles;
    for (Coordinate asteroid : visibleAsteroidsPerAsteroid[monitoringStationCoordinate]) {
        float angle = calculateAngle(monitoringStationCoordinate, asteroid);
        if (std::find(allAngles.begin(), allAngles.end(), angle) == allAngles.end()) {
            allAngles.push_back(angle);
        }
    }

    sort(allAngles.begin(), allAngles.end());
    
    while (vaporizedAsteroids < number) {
        for (float angle : allAngles) {
            std::vector<Coordinate> asteroidsInAngle;
            
            for (Coordinate asteroid : visibleAsteroidsPerAsteroid[monitoringStationCoordinate]) {
                if (calculateAngle(monitoringStationCoordinate, asteroid) == angle) {
                    asteroidsInAngle.push_back(asteroid);
                }
            }
            int minDistance = std::abs(asteroidsInAngle[0].y - monitoringStationCoordinate.y) + std::abs(asteroidsInAngle[0].x - monitoringStationCoordinate.x);
            Coordinate asteroidToVaporize = asteroidsInAngle[0];
            for (Coordinate asteroid : asteroidsInAngle) {
                int distance = std::abs(asteroid.y - monitoringStationCoordinate.y) + std::abs(asteroid.x - monitoringStationCoordinate.x);
                if (distance < minDistance) {
                    minDistance = distance;
                    asteroidToVaporize = asteroid;
                }
            }

            // wrong stuff gets selected here
            for (auto i = visibleAsteroidsPerAsteroid[monitoringStationCoordinate].begin(); i != visibleAsteroidsPerAsteroid[monitoringStationCoordinate].end(); i++) {
                if (i->x == asteroidToVaporize.x && i->y == asteroidToVaporize.y) {
                    result = *i;
                    visibleAsteroidsPerAsteroid[monitoringStationCoordinate].erase(i);
                    vaporizedAsteroids += 1;
                    break;
                }
            }
            if (vaporizedAsteroids == number) {
                break;
            }
        }
    }
    return result;
}

#include "FileLoader.hpp"

#include "MonitorStationLocation.hpp"

#include <iostream>

int main() {
    FileLoader fileLoader;
    std::vector<std::string> asteroidMap = fileLoader.getLinesFromFile("10-december/input.txt");
   
    MonitorStationLocation monitorStationLocation;
    std::pair<Coordinate, int> coordinate = monitorStationLocation.getBestLocation(asteroidMap);

    std::cout << "The result for puzzle one is: " << coordinate.second << std::endl;
    Coordinate vaporizedAsteroid = monitorStationLocation.getVaporizedCoordinate(coordinate.first, 200);
    std::cout << "The result for puzzle two is: " << vaporizedAsteroid.x *100 + vaporizedAsteroid.y  << std::endl;
    return 0;
}

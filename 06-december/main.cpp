#include "FileLoader.hpp"
#include "SpaceNavigation.hpp"

#include <iostream>

int main() {
    FileLoader fileLoader;
    std::vector<std::string> map = fileLoader.getLinesFromFile("06-december/input.txt");
    
    SpaceNavigation navigator(map);
    std::cout << "The result for puzzle one is: " << navigator.totalOrbits() << std::endl;
    std::cout << "The result for puzzle two is: " << navigator.getMinOrbitalTransfers("YOU", "SAN") << std::endl;
    
    return 0;
}

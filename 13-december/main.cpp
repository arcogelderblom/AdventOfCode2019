#include "FileLoader.hpp"

#include "ArcadeCabinet.hpp"
#include <iostream>

int main() {
    FileLoader fileLoader;
    std::vector<std::string> codes = fileLoader.getCommaSeparatedVectorFromFile("13-december/input.txt");
    
    std::vector<long> program;
    for (std::string code : codes) {
        program.push_back(std::stol(code));
    }
    
    ArcadeCabinet arcadeCabinet(program);
    
    int amountOfBlocks = 0;
    std::vector<Tile> tiles = arcadeCabinet.getTiles();
    for (Tile tile : tiles) {
        if (tile.tileId == 2) { // block tile id
            amountOfBlocks += 1;
        }
    }
    std::cout << "The result for puzzle one is: " << amountOfBlocks << std::endl;
    std::cout << "The result for puzzle two is: " << std::endl;
}
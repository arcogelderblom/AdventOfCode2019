#include "FileLoader.hpp"

#include "ArcadeCabinet.hpp"
#include <iostream>

int main() {
    FileLoader fileLoader;
    std::vector<std::string> codes = fileLoader.getCommaSeparatedVectorFromFile("13-december/input.txt");
    std::vector<std::string> codes2 = fileLoader.getCommaSeparatedVectorFromFile("13-december/input-2.txt");
    
    std::vector<long> program;
    for (std::string code : codes) {
        program.push_back(std::stol(code));
    }
    std::vector<long> program2;
    for (std::string code : codes2) {
        program2.push_back(std::stol(code));
    }
    
    ArcadeCabinet arcadeCabinet(program);
    ArcadeCabinet arcadeCabinet2(program2);  
    int amountOfBlocks = 0;
    std::vector<Tile> tiles = arcadeCabinet.getTiles();
    arcadeCabinet.printScreen(tiles);
    for (Tile tile : tiles) {
        if (tile.tileId == 2) { // block tile id
            amountOfBlocks += 1;
        }
    }

    std::cout << "The result for puzzle one is: " << amountOfBlocks << std::endl;
    std::cout << "The result for puzzle two is: " << arcadeCabinet2.play() << std::endl;
}
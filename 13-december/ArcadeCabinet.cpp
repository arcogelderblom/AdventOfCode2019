#include "ArcadeCabinet.hpp"

ArcadeCabinet::ArcadeCabinet(std::vector<long> & memory) :
    intcodeComputer(memory)
{}

std::vector<Tile> ArcadeCabinet::getTiles() {
    std::vector<Tile> tiles;

    int output = intcodeComputer.getOutputUsingInput(std::vector<int>());
    while(output != -1) {
        Tile tile;
        tile.x = output;
        tile.y = intcodeComputer.getOutputUsingInput(std::vector<int>());
        tile.tileId = intcodeComputer.getOutputUsingInput(std::vector<int>());
        tiles.push_back(tile);
        output = intcodeComputer.getOutputUsingInput(std::vector<int>());
    }
    return tiles;
}

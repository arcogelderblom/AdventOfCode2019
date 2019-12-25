#pragma once

#include <vector>

#include "IntcodeComputer.hpp"

struct Tile {
    int x;
    int y;
    int tileId;
};

class ArcadeCabinet {
    private:
        IntcodeComputer intcodeComputer;
        std::pair<int, int> getBallPosition(std::vector<Tile> tiles);
        std::pair<int, int> getPaddlePosition(std::vector<Tile> tiles);
    public:
        ArcadeCabinet(std::vector<long> & memory);
        std::vector<Tile> getTiles();
        void printScreen(std::vector<Tile> tiles);
        int play();
};
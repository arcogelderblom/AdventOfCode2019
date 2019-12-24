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
    public:
        ArcadeCabinet(std::vector<long> & memory);
        std::vector<Tile> getTiles();
};
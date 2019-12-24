#include <gtest/gtest.h>

#include "ArcadeCabinet.hpp"

TEST(DecemberThirteenTest, PuzzleOneTestOne) {
    std::vector<long> program = {4,1,4,2,4,2,4,6,4,5,4,4};
    ArcadeCabinet arcadeCabinet(program);
    
    int amountOfBlocks = 0;
    std::vector<Tile> tiles = arcadeCabinet.getTiles();
    for (Tile tile : tiles) {
        if (tile.tileId == 2) { // block tile id
            amountOfBlocks += 1;
        }
    }
    ASSERT_EQ(amountOfBlocks, 1);
}

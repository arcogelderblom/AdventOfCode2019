#include "ArcadeCabinet.hpp"

#include <iostream>

ArcadeCabinet::ArcadeCabinet(std::vector<long> & memory) :
    intcodeComputer(memory)
{}

std::vector<Tile> ArcadeCabinet::getTiles() {
    std::vector<Tile> tiles;
    
    int output = intcodeComputer.getOutputUsingInput(std::vector<int>());
    while(output != -2) {
        Tile tile;
        tile.x = output;
        tile.y = intcodeComputer.getOutputUsingInput(std::vector<int>());
        tile.tileId = intcodeComputer.getOutputUsingInput(std::vector<int>());
        
        tiles.push_back(tile);
        
        output = intcodeComputer.getOutputUsingInput(std::vector<int>());
    }
    return tiles;
}

void ArcadeCabinet::printScreen(std::vector<Tile> tiles) {
    int lowestX = 0;
    int highestX = 0;
    int lowestY = 0;
    int highestY = 0;

    for (Tile tile : tiles) {
        if (tile.x > highestX) {
            highestX = tile.x;
        }
        if (tile.y > highestY) {
            highestY = tile.y;
        }
        if (tile.x < lowestX) {
            lowestX = tile.x;
        }
        if (tile.y < lowestY) {
            lowestY = tile.y;
        }
    }

    char playingField[highestY + std::abs(lowestY)][highestX + std::abs(lowestX)];
    for (Tile tile : tiles) {
        if (tile.tileId == 0) {
            playingField[tile.y + std::abs(lowestY)][tile.x + std::abs(lowestX)] = ' ';
        } else if (tile.tileId == 1) {
            playingField[tile.y + std::abs(lowestY)][tile.x + std::abs(lowestX)] = '|';
        } else if (tile.tileId == 2) {
            playingField[tile.y + std::abs(lowestY)][tile.x + std::abs(lowestX)] = '#';
        } else if (tile.tileId == 3) {
            playingField[tile.y + std::abs(lowestY)][tile.x + std::abs(lowestX)] = '-';
        } else if (tile.tileId == 4) {
            playingField[tile.y + std::abs(lowestY)][tile.x + std::abs(lowestX)] = 'o';
        }
    }

    for (int y = std::abs(lowestY); y < highestY + std::abs(lowestY); y++) {
        for (int x = std::abs(lowestX); x <= highestX + std::abs(lowestX); x++) {
            std::cout << playingField[y][x];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::pair<int, int> ArcadeCabinet::getBallPosition(std::vector<Tile> tiles) {
    for (Tile tile : tiles) {
        if (tile.tileId == 4) {
            return std::make_pair(tile.x, tile.y);
        }
    }
    return std::pair<int,int>();
}

std::pair<int, int> ArcadeCabinet::getPaddlePosition(std::vector<Tile> tiles) {
    for (Tile tile : tiles) {
        if (tile.tileId == 3) {
            return std::make_pair(tile.x, tile.y);
        }
    }
    return std::pair<int,int>();
}

int ArcadeCabinet::play() {
    std::vector<Tile> tiles;
    int score = 0;
    bool programStarted = false;
    std::vector<int> inputs;
    std::pair<int,int> oldBallPosition;
    
    int output = intcodeComputer.getOutputUsingInput(inputs);
    while(output != -2) {
        Tile tile;
        tile.x = output;
        tile.y = intcodeComputer.getOutputUsingInput(inputs);
        if (tile.x == -1 && tile.y == 0) { // it is a score instead of a tile
            score = intcodeComputer.getOutputUsingInput(inputs);
            // when score is printed the program is started
            programStarted = true;
        }
        else {
            tile.tileId = intcodeComputer.getOutputUsingInput(inputs);
            bool tileFound = false;
            for (Tile & tileInVector : tiles) {
                if (tileInVector.x == tile.x && tileInVector.y == tile.y) {
                    tileFound = true;
                    tileInVector.tileId = tile.tileId; 
                }
            }
            if (!tileFound) {
                tiles.push_back(tile);
            }
        }

        if (programStarted) {
            std::pair<int,int> ballPosition = getBallPosition(tiles);
            std::pair<int,int> paddlePosition = getPaddlePosition(tiles);
            if (ballPosition.first != 0 && paddlePosition.first != 0 && oldBallPosition != ballPosition) {
                printScreen(tiles);
                if (ballPosition.first > paddlePosition.first) {
                    inputs.push_back(1);
                } else if (ballPosition.first == paddlePosition.first) {
                    inputs.push_back(0);
                } else if (ballPosition.first < paddlePosition.first) {
                    inputs.push_back(-1);
                }
            }
            oldBallPosition = ballPosition;
        }
        
        output = intcodeComputer.getOutputUsingInput(inputs);
    }
    return score;
}

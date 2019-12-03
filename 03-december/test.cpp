#include <gtest/gtest.h>

#include <vector>
#include "WirePath.hpp"
#include "ManhattanDistanceCalculator.hpp"

TEST(DecemberThirdTests, PuzzleOneTestOne) {
    std::vector<std::vector<std::string>> wireInstructions{{"R8","U5","L5","D3"}, {"U7","R6","D4","L4"}};
    std::vector<WirePath> wirePaths;
    for (std::vector<std::string> wireInstruction : wireInstructions) {
        WirePath wirePath(wireInstruction);
        wirePaths.push_back(wirePath);
    }

    ManhattanDistanceCalculator calculator;
    ASSERT_EQ(calculator.getManhattanShortestDistance(wirePaths), 6);
}

TEST(DecemberThirdTests, PuzzleOneTestTwo) {
     std::vector<std::vector<std::string>> wireInstructions{{"R75","D30","R83","U83","L12","D49","R71","U7","L72"}, 
                                                       {"U62","R66","U55","R34","D71","R55","D58","R83"}};
    std::vector<WirePath> wirePaths;
    for (std::vector<std::string> wireInstruction : wireInstructions) {
        WirePath wirePath(wireInstruction);
        wirePaths.push_back(wirePath);
    }

    ManhattanDistanceCalculator calculator;
    ASSERT_EQ(calculator.getManhattanShortestDistance(wirePaths), 159);
}

TEST(DecemberThirdTests, PuzzleOneTestThree) {
     std::vector<std::vector<std::string>> wireInstructions{{"R98","U47","R26","D63","R33","U87","L62","D20","R33","U53","R51"}, 
                                                       {"U98","R91","D20","R16","D67","R40","U7","R15","U6","R7"}};
    std::vector<WirePath> wirePaths;
    for (std::vector<std::string> wireInstruction : wireInstructions) {
        WirePath wirePath(wireInstruction);
        wirePaths.push_back(wirePath);
    }

    ManhattanDistanceCalculator calculator;
    ASSERT_EQ(calculator.getManhattanShortestDistance(wirePaths), 135);
}

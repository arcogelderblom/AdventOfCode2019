#include <gtest/gtest.h>

#include <vector>
#include "IntcodeComputer.hpp"

TEST(DecemberSecondTests, PuzzleOneTestOne) {
    std::vector<int> memory{1,0,0,0,99};
    IntcodeComputer computer(memory);
   
    ASSERT_EQ(computer.getResultFromAddress(0), 2);
}

TEST(DecemberSecondTests, PuzzleOneTestTwo) {
    std::vector<int> memory{2,3,0,3,99};
    IntcodeComputer computer(memory);
    
    ASSERT_EQ(computer.getResultFromAddress(3), 6);
}

TEST(DecemberSecondTests, PuzzleOneTestThree) {
    std::vector<int> memory{2,4,4,5,99,0};
    IntcodeComputer computer(memory);

    ASSERT_EQ(computer.getResultFromAddress(5), 9801);
}

TEST(DecemberSecondTests, PuzzleOneTestFour) {
    std::vector<int> memory{1,1,1,4,99,5,6,0,99};
    IntcodeComputer computer(memory);

    ASSERT_EQ(computer.getResultFromAddress(0), 30);
}

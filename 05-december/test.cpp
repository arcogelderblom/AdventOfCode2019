#include "IntcodeComputer.hpp"
#include <gtest/gtest.h>


TEST(DecemberFiveTests, PuzzleOneTestOne) {
    std::vector<int> program = {1002,4,3,4,33};
    IntcodeComputer intcodeComputer(program);
    ASSERT_EQ(intcodeComputer.getResultFromAddress(4), 99);
}

TEST(DecemberFiveTests, PuzzleOneTestTwo) {
    std::vector<int> program = {1101,100,-1,4,0};
    IntcodeComputer intcodeComputer(program);
    ASSERT_EQ(intcodeComputer.getResultFromAddress(4), 99);
}

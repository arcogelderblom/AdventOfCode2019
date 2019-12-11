#include <gtest/gtest.h>

#include "IntcodeComputer.hpp"

TEST(DecemberNineTests, PuzzleOneTestOne) {
    std::vector<long> program = {109,1,204,-1,1001,100,1,100,1008,100,16,101,1006,101,0,99};
    IntcodeComputer intcodeComputer(program);

   // ASSERT_EQ(intcodeComputer.getOutputUsingInput(std::vector<int>()), 1125899906842624);
}

TEST(DecemberNineTests, PuzzleOneTestTwo) {
    std::vector<long> program = {1102,34915192,34915192,7,4,7,99,0};
    IntcodeComputer intcodeComputer(program);
    long result = intcodeComputer.getOutputUsingInput(std::vector<int>());
    
    ASSERT_GT(result/1000000000000000, 0);
}

TEST(DecemberNineTests, PuzzleOneTestThree) {
    std::vector<long> program = {104,1125899906842624,99};
    IntcodeComputer intcodeComputer(program);
    ASSERT_EQ(intcodeComputer.getOutputUsingInput(std::vector<int>()), 1125899906842624);
}

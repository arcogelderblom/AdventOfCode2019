#include <gtest/gtest.h>

#include <vector>
#include "OpcodeCalculator.hpp"

TEST(DecemberSecondTests, PuzzleOneTestOne) {
    OpcodeCalculator calculator;
    std::vector<int> opcode{1,0,0,0,99};
    ASSERT_EQ(calculator.calculateOpcode(opcode, 0), 2);
}

TEST(DecemberSecondTests, PuzzleOneTestTwo) {
    OpcodeCalculator calculator;
    std::vector<int> opcode{2,3,0,3,99};
    ASSERT_EQ(calculator.calculateOpcode(opcode, 3), 6);
}

TEST(DecemberSecondTests, PuzzleOneTestThree) {
    OpcodeCalculator calculator;
    std::vector<int> opcode{2,4,4,5,99,0};
    ASSERT_EQ(calculator.calculateOpcode(opcode, 5), 9801);
}

TEST(DecemberSecondTests, PuzzleOneTestFour) {
    OpcodeCalculator calculator;
    std::vector<int> opcode{1,1,1,4,99,5,6,0,99};
    ASSERT_EQ(calculator.calculateOpcode(opcode, 0), 30);
}

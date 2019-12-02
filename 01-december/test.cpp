#include <gtest/gtest.h>

#include "FuelRequirementCalculator.hpp"

TEST(DecemberFirstTests, PuzzleOneTestOne) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirementPuzzleOne(12), 2);
}

TEST(DecemberFirstTests, PuzzleOneTestTwo) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirementPuzzleOne(14), 2);
}

TEST(DecemberFirstTests, PuzzleOneTestThree) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirementPuzzleOne(1969), 654);
}

TEST(DecemberFirstTests, PuzzleOneTestFour) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirementPuzzleOne(100756), 33583);
}

TEST(DecemberFirstTests, PuzzleTwoTestOne) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirementPuzzleTwo(12), 2);
}

TEST(DecemberFirstTests, PuzzleTwoTestTwo) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirementPuzzleTwo(14), 2);
}

TEST(DecemberFirstTests, PuzzleTwoTestThree) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirementPuzzleTwo(1969), 966);
}

TEST(DecemberFirstTests, PuzzleTwoTestFour) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirementPuzzleTwo(100756), 50346);
}

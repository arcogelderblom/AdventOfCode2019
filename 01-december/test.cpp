#include <gtest/gtest.h>

#include "FuelRequirementCalculator.hpp"

TEST(DecemberFirstTests, TestOne) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirement(12), 2);
}

TEST(DecemberFirstTests, TestTwo) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirement(14), 2);
}

TEST(DecemberFirstTests, TestThree) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirement(1969), 654);
}

TEST(DecemberFirstTests, TestFour) {
    FuelRequirementCalculator calculator;
    ASSERT_EQ(calculator.getFuelRequirement(100756), 33583);
}
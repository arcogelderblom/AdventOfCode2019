#include <gtest/gtest.h>

#include "PasswordGenerator.hpp"

TEST(DecemberFourTests, PuzzleOneTestOne) {
    PasswordGenerator generator;
    std::vector<int> password = generator.getVectorFromInt(111111);
    ASSERT_TRUE(generator.isValidPassword(password));
}

TEST(DecemberFourTests, PuzzleOneTestTwo) {
    PasswordGenerator generator;
    std::vector<int> password = generator.getVectorFromInt(123450);
    ASSERT_FALSE(generator.isValidPassword(password));
}

TEST(DecemberFourTests, PuzzleOneTestThree) {
    PasswordGenerator generator;
    std::vector<int> password = generator.getVectorFromInt(123789);
    ASSERT_FALSE(generator.isValidPassword(password));
}

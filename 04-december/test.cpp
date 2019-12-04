#include <gtest/gtest.h>

#include "PasswordGenerator.hpp"

TEST(DecemberFourTests, PuzzleOneTestOne) {
    PasswordGenerator generator;
    std::vector<int> password = generator.getVectorFromInt(111111);
    ASSERT_TRUE(generator.isValidPassword1(password));
}

TEST(DecemberFourTests, PuzzleOneTestTwo) {
    PasswordGenerator generator;
    std::vector<int> password = generator.getVectorFromInt(123450);
    ASSERT_FALSE(generator.isValidPassword1(password));
}

TEST(DecemberFourTests, PuzzleOneTestThree) {
    PasswordGenerator generator;
    std::vector<int> password = generator.getVectorFromInt(123789);
    ASSERT_FALSE(generator.isValidPassword1(password));
}

TEST(DecemberFourTests, PuzzleTwoTestOne) {
    PasswordGenerator generator;
    std::vector<int> password = generator.getVectorFromInt(112233);
    ASSERT_TRUE(generator.isValidPassword2(password));
}

TEST(DecemberFourTests, PuzzleTwoTestTwo) {
    PasswordGenerator generator;
    std::vector<int> password = generator.getVectorFromInt(123444);
    ASSERT_FALSE(generator.isValidPassword2(password));
}

TEST(DecemberFourTests, PuzzleTwoTestThree) {
    PasswordGenerator generator;
    std::vector<int> password = generator.getVectorFromInt(111122);
    ASSERT_TRUE(generator.isValidPassword2(password));
}

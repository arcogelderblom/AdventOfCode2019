#include <gtest/gtest.h>

#include <vector>
#include "FileLoader.hpp"

TEST(FileLoaderTests, PuzzleOneTestOne) {
    FileLoader fileLoader;
    std::vector<std::string> lines = fileLoader.getLinesFromFile("common/lines-test.txt");
    int val = 1;
    for (const std::string & line : lines) {
        ASSERT_EQ(line, std::to_string(val));
        val++;
    }
}

TEST(DecemberSecondTests, PuzzleOneTestTwo) {
    FileLoader fileLoader;
    std::vector<std::string> commaSeparated = fileLoader.getCommaSeparatedVectorFromFile("common/comma-separated-test.txt");
    int val = 1;
    for (const std::string & entry : commaSeparated) {
        ASSERT_EQ(entry, std::to_string(val));
        val++;
    }
}

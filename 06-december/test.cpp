#include <gtest/gtest.h>

#include "SpaceNavigation.hpp"

TEST(DecemberFiveTests, PuzzleOneTestOne) {
    std::vector<std::string> map = {"COM)B","B)C","C)D","D)E","E)F","B)G","G)H","D)I","E)J","J)K","K)L"};
    SpaceNavigation spaceNavigation(map);
    ASSERT_EQ(spaceNavigation.totalOrbits(), 42);
}

TEST(DecemberFiveTests, PuzzleTwoTestOne) {
    std::vector<std::string> map = {"COM)B","B)C","C)D","D)E","E)F","B)G","G)H","D)I","E)J","J)K","K)L", "K)YOU", "I)SAN"};
    SpaceNavigation spaceNavigation(map);
    ASSERT_EQ(spaceNavigation.getMinOrbitalTransfers("YOU", "SAN"), 4);
}

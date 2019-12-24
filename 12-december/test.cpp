#include <gtest/gtest.h>

#include "MoonPositionCalculator.hpp"

TEST(DecemberTwelveTest, PuzzleOneTestOne) {
    std::vector<std::string> moonStrings = {"<x=-1, y=0, z=2>",
                                            "<x=2, y=-10, z=-7>",
                                            "<x=4, y=-8, z=8>",
                                            "<x=3, y=5, z=-1>"};

    MoonPositionCalculator moonPositionCalculator;
    std::vector<Moon> moons = moonPositionCalculator.parse(moonStrings);
    int steps = 10;
    moonPositionCalculator.calculate(moons, steps);
    
    std::cout << std::endl;
    ASSERT_EQ(moonPositionCalculator.getTotalEnergy(moons), 179);
}

TEST(DecemberTwelveTest, PuzzleOneTestTwo) {
    std::vector<std::string> moonStrings = {"<x=-8, y=-10, z=0>",
                                            "<x=5, y=5, z=10>",
                                            "<x=2, y=-7, z=3>",
                                            "<x=9, y=-8, z=-3>"};

    MoonPositionCalculator moonPositionCalculator;
    std::vector<Moon> moons = moonPositionCalculator.parse(moonStrings);
    int steps = 100;
    moonPositionCalculator.calculate(moons, steps);
    ASSERT_EQ(moonPositionCalculator.getTotalEnergy(moons), 1940);
}

TEST(DecemberTwelveTest, PuzzleTwoTestOne) {
    std::vector<std::string> moonStrings = {"<x=-1, y=0, z=2>",
                                            "<x=2, y=-10, z=-7>",
                                            "<x=4, y=-8, z=8>",
                                            "<x=3, y=5, z=-1>"};

    MoonPositionCalculator moonPositionCalculator;
    std::vector<Moon> moons = moonPositionCalculator.parse(moonStrings);
    ASSERT_EQ(moonPositionCalculator.getAmountOfStepsRecurringState(moons), 2772);
}

TEST(DecemberTwelveTest, PuzzleTwoTestTwo) {
    std::vector<std::string> moonStrings = {"<x=-8, y=-10, z=0>",
                                            "<x=5, y=5, z=10>",
                                            "<x=2, y=-7, z=3>",
                                            "<x=9, y=-8, z=-3>"};

    MoonPositionCalculator moonPositionCalculator;
    std::vector<Moon> moons = moonPositionCalculator.parse(moonStrings);
    ASSERT_EQ(moonPositionCalculator.getAmountOfStepsRecurringState(moons), 4686774924);
}

#include <gtest/gtest.h>

#include "MonitorStationLocation.hpp"

TEST(DecemberTenTests, PuzzleOneTestOne) {
    std::vector<std::string> asteroidMap = {".#..#",
                                            ".....",
                                            "#####",
                                            "....#",
                                            "...##"};
    
    MonitorStationLocation monitorStationLocation;
    std::pair<Coordinate, int> coordinate = monitorStationLocation.getBestLocation(asteroidMap);
    
    ASSERT_EQ(coordinate.first.x, 3);
    ASSERT_EQ(coordinate.first.y, 4);
    ASSERT_EQ(coordinate.second, 8);
}

TEST(DecemberTenTests, PuzzleOneTestTwo) {
    std::vector<std::string> asteroidMap = {"......#.#.",
                                            "#..#.#....",
                                            "..#######.",
                                            ".#.#.###..",
                                            ".#..#.....",
                                            "..#....#.#",
                                            "#..#....#.",
                                            ".##.#..###",
                                            "##...#..#.",
                                            ".#....####"};
    
    MonitorStationLocation monitorStationLocation;
    std::pair<Coordinate, int> coordinate = monitorStationLocation.getBestLocation(asteroidMap);
    
    ASSERT_EQ(coordinate.first.x, 5);
    ASSERT_EQ(coordinate.first.y, 8);
    ASSERT_EQ(coordinate.second, 33);
}

TEST(DecemberTenTests, PuzzleOneTestThree) {
    std::vector<std::string> asteroidMap = {"#.#...#.#.",
                                            ".###....#.",
                                            ".#....#...",
                                            "##.#.#.#.#",
                                            "....#.#.#.",
                                            ".##..###.#",
                                            "..#...##..",
                                            "..##....##",
                                            "......#...",
                                            ".####.###."};
    
    MonitorStationLocation monitorStationLocation;
    std::pair<Coordinate, int> coordinate = monitorStationLocation.getBestLocation(asteroidMap);
    
    ASSERT_EQ(coordinate.first.x, 1);
    ASSERT_EQ(coordinate.first.y, 2);
    ASSERT_EQ(coordinate.second, 35);
}

TEST(DecemberTenTests, PuzzleOneTestFour) {
    std::vector<std::string> asteroidMap = {".#..#..###",
                                            "####.###.#",
                                            "....###.#.",
                                            "..###.##.#",
                                            "##.##.#.#.",
                                            "....###..#",
                                            "..#.#..#.#",
                                            "#..#.#.###",
                                            ".##...##.#",
                                            ".....#.#.."};
    
    MonitorStationLocation monitorStationLocation;
    std::pair<Coordinate, int> coordinate = monitorStationLocation.getBestLocation(asteroidMap);
    
    ASSERT_EQ(coordinate.first.x, 6);
    ASSERT_EQ(coordinate.first.y, 3);
    ASSERT_EQ(coordinate.second, 41);
}

TEST(DecemberTenTests, PuzzleOneTestFive) {
    std::vector<std::string> asteroidMap = {".#..##.###...#######",
                                            "##.############..##.",
                                            ".#.######.########.#",
                                            ".###.#######.####.#.",
                                            "#####.##.#.##.###.##",
                                            "..#####..#.#########",
                                            "####################",
                                            "#.####....###.#.#.##",
                                            "##.#################",
                                            "#####.##.###..####..",
                                            "..######..##.#######",
                                            "####.##.####...##..#",
                                            ".#####..#.######.###",
                                            "##...#.##########...",
                                            "#.##########.#######",
                                            ".####.#.###.###.#.##",
                                            "....##.##.###..#####",
                                            ".#.#.###########.###",
                                            "#.#.#.#####.####.###",
                                            "###.##.####.##.#..##"};
    
    MonitorStationLocation monitorStationLocation;
    std::pair<Coordinate, int> coordinate = monitorStationLocation.getBestLocation(asteroidMap);
    
    ASSERT_EQ(coordinate.first.x, 11);
    ASSERT_EQ(coordinate.first.y, 13);
    ASSERT_EQ(coordinate.second, 210);
}

TEST(DecemberTenTests, PuzzleTwoTestOne) {
    std::vector<std::string> asteroidMap = {".#..##.###...#######",
                                            "##.############..##.",
                                            ".#.######.########.#",
                                            ".###.#######.####.#.",
                                            "#####.##.#.##.###.##",
                                            "..#####..#.#########",
                                            "####################",
                                            "#.####....###.#.#.##",
                                            "##.#################",
                                            "#####.##.###..####..",
                                            "..######..##.#######",
                                            "####.##.####...##..#",
                                            ".#####..#.######.###",
                                            "##...#.##########...",
                                            "#.##########.#######",
                                            ".####.#.###.###.#.##",
                                            "....##.##.###..#####",
                                            ".#.#.###########.###",
                                            "#.#.#.#####.####.###",
                                            "###.##.####.##.#..##"};
    
    MonitorStationLocation monitorStationLocation;
    std::pair<Coordinate, int> coordinate = monitorStationLocation.getBestLocation(asteroidMap);
    Coordinate vaporizedAsteroid = monitorStationLocation.getVaporizedCoordinate(coordinate.first, 200);
    
    ASSERT_EQ(vaporizedAsteroid.x *100 + vaporizedAsteroid.y, 802);
}

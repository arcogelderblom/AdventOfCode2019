#include <gtest/gtest.h>

#include "Picture.hpp"

TEST(DecemberEightTests, PuzzleOneTestOne) {
    std::string spaceImageFormat = "123456789012";
    Picture pictureDecoder;
    std::vector<Layer> picture = pictureDecoder.decode(spaceImageFormat, 3, 2);
    
    ASSERT_EQ(picture.at(0).at(0).at(0), 1);
    ASSERT_EQ(picture.at(0).at(0).at(1), 2);
    ASSERT_EQ(picture.at(0).at(0).at(2), 3);
    ASSERT_EQ(picture.at(0).at(1).at(0), 4);
    ASSERT_EQ(picture.at(0).at(1).at(1), 5);
    ASSERT_EQ(picture.at(0).at(1).at(2), 6);
    ASSERT_EQ(picture.at(1).at(0).at(0), 7);
    ASSERT_EQ(picture.at(1).at(0).at(1), 8);
    ASSERT_EQ(picture.at(1).at(0).at(2), 9);
    ASSERT_EQ(picture.at(1).at(1).at(0), 0);
    ASSERT_EQ(picture.at(1).at(1).at(1), 1);
    ASSERT_EQ(picture.at(1).at(1).at(2), 2);
}

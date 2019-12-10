#pragma once

#include <vector>
#include <string>

typedef std::vector< std::vector<int> > Layer;

class Picture {
    public:
        std::vector<Layer> decode(std::string spaceImageFormat, int pictureWidth, int pictureHeight);
        void printPicture(std::vector<Layer> picture);
};
#include "Picture.hpp"

#include <iostream>

std::vector<Layer> Picture::decode(std::string spaceImageFormat, int pictureWidth, int pictureHeight) {
    std::vector<Layer> picture;
    for (std::string::size_type i = 0; i < spaceImageFormat.size();) {
        Layer layer;
        
        int height = 0;
        while(height != pictureHeight) {
            int width = 0;
            std::vector<int> row;
            while(width != pictureWidth) {
                int num = spaceImageFormat[i] - '0';
                row.push_back(num);
                i++;
                width++;
            }
            layer.push_back(row);
            height++;
        }
        picture.push_back(layer);

    }
    return picture;
}

void Picture::printPicture(std::vector<Layer> picture) {
    int height = picture[0].size();
    int width = picture[0][0].size();

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int layer = 0;
            if (picture.at(layer).at(i).at(j) == 0) {
                std::cout << " ";
            }
            else if (picture.at(layer).at(i).at(j) == 1) {
                std::cout << "#";
            }
            else if (picture.at(layer).at(i).at(j) == 2) {
                while (picture.at(layer).at(i).at(j) == 2) {
                    layer++;
                }
                if (picture.at(layer).at(i).at(j) == 0) {
                    std::cout << " ";
                }
                else if (picture.at(layer).at(i).at(j) == 1) {
                    std::cout << "#";
                }
            }
        }
        std::cout << std::endl;
    }
}
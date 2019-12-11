#include "FileLoader.hpp"
#include "Picture.hpp"

#include <iostream>

int getAmountOfNumInLayer(Layer layer, int num) {
    int amount = 0;
    for (std::vector<int> row : layer) {
        for (int integer : row) {
            if (integer == num) {
                amount++;
            }
        }
    }
    return amount;
}

int main() {
    FileLoader fileLoader;
    std::vector<std::string> image = fileLoader.getLinesFromFile("08-december/input.txt");
    std::string spaceImageFormat = image[0];
    
    Picture pictureDecoder;
    std::vector<Layer> picture = pictureDecoder.decode(spaceImageFormat, 25, 6);

    Layer layerWithLeastZeroes = picture[0];
    int leastAmount = getAmountOfNumInLayer(picture[0], 0);
    for (Layer layer : picture) {
        int amount = getAmountOfNumInLayer(layer, 0);
        if (amount < leastAmount) {
            leastAmount = amount;
            layerWithLeastZeroes = layer;
        }
    }

    std::cout << "The result for puzzle one is: " << getAmountOfNumInLayer(layerWithLeastZeroes, 1) * getAmountOfNumInLayer(layerWithLeastZeroes, 2) << std::endl;
    std::cout << "The result for puzzle two is: " << std::endl;
    pictureDecoder.printPicture(picture);
    return 0;
}

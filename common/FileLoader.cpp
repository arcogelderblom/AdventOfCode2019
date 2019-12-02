#include "FileLoader.hpp"

#include <iostream>
#include <fstream>
#include <string>

std::vector<std::string> FileLoader::getLinesFromFile(const std::string & filePath) {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream myfile (filePath);
    if (myfile.is_open())
    {
        while (getline(myfile,line))
        {
            lines.push_back(line);
        }
        myfile.close();
    }
    return lines;
}

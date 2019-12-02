#include "FileLoader.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

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

std::vector<std::string> FileLoader::getCommaSeparatedVectorFromFile(const std::string & filePath) {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream myfile (filePath);
    if (myfile.is_open())
    {
        getline(myfile, line);
        
        while (!line.empty()) {
            std::string tmp = line.substr(0, line.find(","));
            lines.push_back(tmp);
            if (line.find(",") == std::string::npos) {
                myfile.close();
                return lines;
            }
            line = line.substr(line.find(",")+1);
        }   
    }
    return lines;
}
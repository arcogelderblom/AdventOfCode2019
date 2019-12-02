#pragma once

#include <string>
#include <vector>

class FileLoader {
    public:
        std::vector<std::string> getLinesFromFile(const std::string & filePath);
};
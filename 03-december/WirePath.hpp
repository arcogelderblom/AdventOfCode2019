#pragma once

#include <vector>
#include <string>

class WirePath {
    private:
        std::vector<std::string> instructions;
    public:
        WirePath(std::vector<std::string> instructions);
        std::vector< std::pair<int, int> > calculatePath();
};
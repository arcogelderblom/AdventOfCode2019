#pragma once

#include <vector>

class IntcodeComputer {
    private:
        std::vector<int> memory;
    public:
        IntcodeComputer(std::vector<int> & memory);
        int getResultFromAddress(int resultAddress);
};
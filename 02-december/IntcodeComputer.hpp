#pragma once

#include <vector>

class IntcodeComputer {
    private:
        std::vector<int> memory;
        int instructionPointer = 0;
        int calcResultOpcode1();
        int calcResultOpcode2();
    public:
        IntcodeComputer(std::vector<int> & memory);
        int getResultFromAddress(int resultAddress);
};
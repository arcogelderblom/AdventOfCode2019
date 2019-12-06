#pragma once

#include <vector>

class IntcodeComputer {
    private:
        std::vector<int> memory;
        int instructionPointer = 0;
        int calcResultOpcode1(bool modeParam1 = false, bool modeParam2 = false);
        int calcResultOpcode2(bool modeParam1 = false, bool modeParam2 = false);
        int calcResultOpcode3();
        int calcResultOpcode4(bool modeParam1 = false);
    public:
        IntcodeComputer(std::vector<int> & memory);
        int getResultFromAddress(int resultAddress);
};
#pragma once

#include <vector>

class IntcodeComputer {
    private:
        std::vector<long> memory;
        int instructionPointer = 0;
        long lastOutputtedValue = 0;
        int inputPointerIndex = 0;
        int currentRelativeBase = 0;
        std::vector<int> inputs;
        int calcResultOpcode1(int modeParam1 = 0, int modeParam2 = 0, int modeParam3 = 0);
        int calcResultOpcode2(int modeParam1 = 0, int modeParam2 = 0, int modeParam3 = 0);
        int calcResultOpcode3(int modeParam1 = 0);
        int calcResultOpcode4(int modeParam1 = 0);
        int calcResultOpcode5(int modeParam1 = 0, int modeParam2 = 0);
        int calcResultOpcode6(int modeParam1 = 0, int modeParam2 = 0);
        int calcResultOpcode7(int modeParam1 = 0, int modeParam2 = 0, int modeParam3 = 0);
        int calcResultOpcode8(int modeParam1 = 0, int modeParam2 = 0, int modeParam3 = 0);
        int calcResultOpcode9(int modeParam1 = 0);
        long getParamValueBasedOnMode(int mode, long param);
        void writeValueBasedOnMode(int mode, long param, long value);
        void calculate();
    public:
        IntcodeComputer(std::vector<long> & memory);
        long getResultFromAddress(int resultAddress);
        long getOutputUsingInput(std::vector<int> input);
};
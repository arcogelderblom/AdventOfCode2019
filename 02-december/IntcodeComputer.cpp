#include "IntcodeComputer.hpp"

#include <iostream>

IntcodeComputer::IntcodeComputer(std::vector<int> & memory): 
    memory(memory)
    {}

int calcResultOpcode1(int param1, int param2) {
    return param1 + param2;
}

int calcResultOpcode2(int param1, int param2) {
    return param1 * param2;
}

int IntcodeComputer::getResultFromAddress(int resultAddress) {
    int instructionPointer = 0;
    int opcode = memory[instructionPointer];
    while (opcode != 99) {
        if (opcode == 1) {
            int parameter1 = memory[instructionPointer+1];
            int parameter2 = memory[instructionPointer+2];
            int parameter3 = memory[instructionPointer+3];
            int result = calcResultOpcode1(memory[parameter1], memory[parameter2]);
            memory[parameter3] = result;
        }
        else if (opcode == 2) {
            int parameter1 = memory[instructionPointer+1];
            int parameter2 = memory[instructionPointer+2];
            int parameter3 = memory[instructionPointer+3];
            int result = calcResultOpcode2(memory[parameter1], memory[parameter2]);
            memory[parameter3] = result;
        }
        instructionPointer += 4;
        opcode = memory[instructionPointer];
    }
    
    return memory[resultAddress];
}

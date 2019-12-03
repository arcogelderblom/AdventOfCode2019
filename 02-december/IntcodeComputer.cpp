#include "IntcodeComputer.hpp"

#include <iostream>

IntcodeComputer::IntcodeComputer(std::vector<int> & memory): 
    memory(memory)
    {}

int IntcodeComputer::calcResultOpcode1() {
    int parameter1 = memory[instructionPointer+1];
    int parameter2 = memory[instructionPointer+2];
    int parameter3 = memory[instructionPointer+3];
    memory[parameter3] = memory[parameter1] + memory[parameter2];
    return memory[parameter3];
}

int IntcodeComputer::calcResultOpcode2() {
    int parameter1 = memory[instructionPointer+1];
    int parameter2 = memory[instructionPointer+2];
    int parameter3 = memory[instructionPointer+3];
    memory[parameter3] = memory[parameter1] * memory[parameter2];
    return memory[parameter3];
}

int IntcodeComputer::getResultFromAddress(int resultAddress) {
    int opcode = memory[instructionPointer];
    while (opcode != 99) {
        if (opcode == 1) {
            calcResultOpcode1();
            instructionPointer += 4;
        }
        else if (opcode == 2) {
            calcResultOpcode2();
            instructionPointer += 4;
        }
        opcode = memory[instructionPointer];
    }
    
    return memory[resultAddress];
}

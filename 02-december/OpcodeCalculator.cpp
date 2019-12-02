#include "OpcodeCalculator.hpp"

#include <iostream>

int OpcodeCalculator::calculateOpcode(std::vector<int> opcode, int resultIndex) {
    int currentOpcodeIndex = 0;
    while (opcode[currentOpcodeIndex] != 99) {
        if (opcode[currentOpcodeIndex] == 1) {
            opcode[opcode[currentOpcodeIndex+3]] = opcode[opcode[currentOpcodeIndex+1]] + opcode[opcode[currentOpcodeIndex+2]];
        }
        else if (opcode[currentOpcodeIndex] == 2) {
            opcode[opcode[currentOpcodeIndex+3]] = opcode[opcode[currentOpcodeIndex+1]] * opcode[opcode[currentOpcodeIndex+2]];
        }
        currentOpcodeIndex += 4;
    }
    
    return opcode[resultIndex];
}

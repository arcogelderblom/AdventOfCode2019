#include "IntcodeComputer.hpp"

#include <iostream>
#include <unistd.h>

IntcodeComputer::IntcodeComputer(std::vector<int> & memory): 
    memory(memory)
    {}

int IntcodeComputer::calcResultOpcode1(bool modeParam1, bool modeParam2) {
    int parameter1 = memory[instructionPointer+1];
    int parameter2 = memory[instructionPointer+2];
    int parameter3 = memory[instructionPointer+3];

    int value1 = (modeParam1) ? parameter1 : memory[parameter1];
    int value2 = (modeParam2) ? parameter2 : memory[parameter2];
    
    memory[parameter3] = value1 + value2;
    return 4;
}

int IntcodeComputer::calcResultOpcode2(bool modeParam1, bool modeParam2) {
    int parameter1 = memory[instructionPointer+1];
    int parameter2 = memory[instructionPointer+2];
    int parameter3 = memory[instructionPointer+3];

    int value1 = (modeParam1) ? parameter1 : memory[parameter1];
    int value2 = (modeParam2) ? parameter2 : memory[parameter2];
    
    memory[parameter3] = value1 * value2;
    return 4;
}

int IntcodeComputer::calcResultOpcode3() {
    int x; 
    std::cout << "Type a number as input: "; // Type a number and press enter
    std::cin >> x; // Get user input from the keyboard
    int parameter1 = memory[instructionPointer+1];
    memory[parameter1] = x;
    return 2;
}

int IntcodeComputer::calcResultOpcode4(bool modeParam1) {
    int parameter1 = memory[instructionPointer+1];
    int value1 = (modeParam1) ? parameter1 : memory[parameter1];
    std::cout << "Output: " << value1 << std::endl;
    return 2;
}

int IntcodeComputer::calcResultOpcode5(bool modeParam1, bool modeParam2) {
    int parameter1 = memory[instructionPointer+1];
    int parameter2 = memory[instructionPointer+2];
    
    int value1 = (modeParam1) ? parameter1 : memory[parameter1];
    int value2 = (modeParam2) ? parameter2 : memory[parameter2];
    
    if (value1 != 0) {
        instructionPointer = value2;
        return 0;
    }

    return 3;
}

int IntcodeComputer::calcResultOpcode6(bool modeParam1, bool modeParam2) {
    int parameter1 = memory[instructionPointer+1];
    int parameter2 = memory[instructionPointer+2];
    
    int value1 = (modeParam1) ? parameter1 : memory[parameter1];
    int value2 = (modeParam2) ? parameter2 : memory[parameter2];
    
    if (value1 == 0) {
        instructionPointer = value2;
        return 0;
    }
    return 3;
}

int IntcodeComputer::calcResultOpcode7(bool modeParam1, bool modeParam2) {
    int parameter1 = memory[instructionPointer+1];
    int parameter2 = memory[instructionPointer+2];
    int parameter3 = memory[instructionPointer+3];

    int value1 = (modeParam1) ? parameter1 : memory[parameter1];
    int value2 = (modeParam2) ? parameter2 : memory[parameter2];
    
    memory[parameter3] = (value1 < value2) ? 1 : 0;
    return 4;
}

int IntcodeComputer::calcResultOpcode8(bool modeParam1, bool modeParam2) {
    int parameter1 = memory[instructionPointer+1];
    int parameter2 = memory[instructionPointer+2];
    int parameter3 = memory[instructionPointer+3];

    int value1 = (modeParam1) ? parameter1 : memory[parameter1];
    int value2 = (modeParam2) ? parameter2 : memory[parameter2];
    
    memory[parameter3] = (value1 == value2) ? 1 : 0;
    return 4;
}

int IntcodeComputer::getResultFromAddress(int resultAddress) {
    int opcode = memory[instructionPointer];
    
    while (opcode != 99) {
        bool modeParam1 = false;
        bool modeParam2 = false;
        
        if (opcode > 99) {
            modeParam2 = opcode / 1000;
            opcode = opcode % 1000;
            
            modeParam1 = opcode / 100;
            opcode = opcode % 100;
        }
        
        if (opcode == 1) {
            instructionPointer += calcResultOpcode1(modeParam1, modeParam2);
        }
        else if (opcode == 2) {
            instructionPointer += calcResultOpcode2(modeParam1, modeParam2);
        }
        else if (opcode == 3) {
            instructionPointer += calcResultOpcode3();
        }
        else if (opcode == 4) {
            instructionPointer += calcResultOpcode4(modeParam1);
        }
        else if (opcode == 5) {
            instructionPointer += calcResultOpcode5(modeParam1, modeParam2);
        }
        else if (opcode == 6) {
            instructionPointer += calcResultOpcode6(modeParam1, modeParam2);
        }
        else if (opcode == 7) {
            instructionPointer += calcResultOpcode7(modeParam1, modeParam2);
        }
        else if (opcode == 8) {
            instructionPointer += calcResultOpcode8(modeParam1, modeParam2);
        }
        opcode = memory[instructionPointer];
    }
    
    return memory[resultAddress];
}

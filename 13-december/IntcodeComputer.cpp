#include "IntcodeComputer.hpp"

#include <iostream>

IntcodeComputer::IntcodeComputer(std::vector<long> & memory): 
    memory(memory)
    {}

long IntcodeComputer::getParamValueBasedOnMode(int mode, long param) {
    if (mode == 0) {
        return memory[param];
    }
    else if (mode == 1) {
        return param;
    }
    else if (mode == 2) {
        return memory[param + currentRelativeBase];
    }
    return 0;
}

void IntcodeComputer::writeValueBasedOnMode(int mode, long param, long value) {
    int address = 0;
    if (mode == 2) {
        address = param + currentRelativeBase;
    }
    // there is no mode 1 for writing values
    else if (mode == 0) {
        address = param;
    }

    while(address >= memory.size()) {
        memory.push_back(0);
    }
   
    memory[address] = value;
}

int IntcodeComputer::calcResultOpcode1(int modeParam1, int modeParam2, int modeParam3) {
    long parameter1 = memory[instructionPointer+1];
    long parameter2 = memory[instructionPointer+2];
    long parameter3 = memory[instructionPointer+3];

    long value1 = getParamValueBasedOnMode(modeParam1, parameter1);
    long value2 = getParamValueBasedOnMode(modeParam2, parameter2);
    
    writeValueBasedOnMode(modeParam3, parameter3, value1 + value2);
    return 4;
}

int IntcodeComputer::calcResultOpcode2(int modeParam1, int modeParam2, int modeParam3) {
    long parameter1 = memory[instructionPointer+1];
    long parameter2 = memory[instructionPointer+2];
    long parameter3 = memory[instructionPointer+3];

    long value1 = getParamValueBasedOnMode(modeParam1, parameter1);
    long value2 = getParamValueBasedOnMode(modeParam2, parameter2);
    
    writeValueBasedOnMode(modeParam3, parameter3, value1 * value2);
    return 4;
}

int IntcodeComputer::calcResultOpcode3(int modeParam1) {
    int x; 
    if (inputs.empty()) { 
        std::cout << "Type a number as input: "; // Type a number and press enter
        std::cin >> x; // Get user input from the keyboard
    } else {
        x = inputs[inputPointerIndex];
        inputPointerIndex++;
    }
    long parameter1 = memory[instructionPointer+1];
    writeValueBasedOnMode(modeParam1, parameter1, x);
    return 2;
}

int IntcodeComputer::calcResultOpcode4(int modeParam1) {
    long parameter1 = memory[instructionPointer+1];
    long value1 = getParamValueBasedOnMode(modeParam1, parameter1);

    lastOutputtedValue = value1;
    return 2;
}

int IntcodeComputer::calcResultOpcode5(int modeParam1, int modeParam2) {
    long parameter1 = memory[instructionPointer+1];
    long parameter2 = memory[instructionPointer+2];
    
    long value1 = getParamValueBasedOnMode(modeParam1, parameter1);
    long value2 = getParamValueBasedOnMode(modeParam2, parameter2);
    
    if (value1 != 0) {
        instructionPointer = value2;
        return 0;
    }

    return 3;
}

int IntcodeComputer::calcResultOpcode6(int modeParam1, int modeParam2) {
    long parameter1 = memory[instructionPointer+1];
    long parameter2 = memory[instructionPointer+2];
    
    long value1 = getParamValueBasedOnMode(modeParam1, parameter1);
    long value2 = getParamValueBasedOnMode(modeParam2, parameter2);
    
    if (value1 == 0) {
        instructionPointer = value2;
        return 0;
    }
    return 3;
}

int IntcodeComputer::calcResultOpcode7(int modeParam1, int modeParam2, int modeParam3) {
    long parameter1 = memory[instructionPointer+1];
    long parameter2 = memory[instructionPointer+2];
    long parameter3 = memory[instructionPointer+3];

    long value1 = getParamValueBasedOnMode(modeParam1, parameter1);
    long value2 = getParamValueBasedOnMode(modeParam2, parameter2);
    
    writeValueBasedOnMode(modeParam3, parameter3, (value1 < value2) ? 1 : 0);
    return 4;
}

int IntcodeComputer::calcResultOpcode8(int modeParam1, int modeParam2, int modeParam3) {
    long parameter1 = memory[instructionPointer+1];
    long parameter2 = memory[instructionPointer+2];
    long parameter3 = memory[instructionPointer+3];

    long value1 = getParamValueBasedOnMode(modeParam1, parameter1);
    long value2 = getParamValueBasedOnMode(modeParam2, parameter2);
    
    writeValueBasedOnMode(modeParam3, parameter3, (value1 == value2) ? 1 : 0);
    return 4;
}

int IntcodeComputer::calcResultOpcode9(int modeParam1) {
    long parameter1 = memory[instructionPointer+1];

    long value1 = getParamValueBasedOnMode(modeParam1, parameter1);
    currentRelativeBase += value1;
    return 2;
}

void IntcodeComputer::calculate() {
    int opcode = memory[instructionPointer];
    while (opcode != 99) {
        int modeParam1 = 0;
        int modeParam2 = 0;
        int modeParam3 = 0;

        if (opcode > 99) {
            modeParam3 = opcode / 10000;
            opcode = opcode % 10000;

            modeParam2 = opcode / 1000;
            opcode = opcode % 1000;
            
            modeParam1 = opcode / 100;
            opcode = opcode % 100;
        }
        
        if (opcode == 1) {
            instructionPointer += calcResultOpcode1(modeParam1, modeParam2, modeParam3);
        }
        else if (opcode == 2) {
            instructionPointer += calcResultOpcode2(modeParam1, modeParam2, modeParam3);
        }
        else if (opcode == 3) {
            if (inputPointerIndex > inputs.size()){
                return; // return and wait for new input
            }
            instructionPointer += calcResultOpcode3(modeParam1);
        }
        else if (opcode == 4) {
            instructionPointer += calcResultOpcode4(modeParam1);
            return;
        }
        else if (opcode == 5) {
            instructionPointer += calcResultOpcode5(modeParam1, modeParam2);
        }
        else if (opcode == 6) {
            instructionPointer += calcResultOpcode6(modeParam1, modeParam2);
        }
        else if (opcode == 7) {
            instructionPointer += calcResultOpcode7(modeParam1, modeParam2, modeParam3);
        }
        else if (opcode == 8) {
            instructionPointer += calcResultOpcode8(modeParam1, modeParam2, modeParam3);
        }
        else if (opcode == 9) {
            instructionPointer += calcResultOpcode9(modeParam1);
        }
        
        opcode = memory[instructionPointer];
        
    }
    return;
}

long IntcodeComputer::getResultFromAddress(int resultAddress) { 
    instructionPointer = 0;
    calculate();
    return memory[resultAddress];
}

long IntcodeComputer::getOutputUsingInput(std::vector<int> input) {
    if (memory[instructionPointer] != 99) {
        inputs = input;
        calculate();
        return lastOutputtedValue;
    }
    return -2;
}

#include "IntcodeComputer.hpp"

#include <iostream>

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
    if (inputs.empty()) { 
        std::cout << "Type a number as input: "; // Type a number and press enter
        std::cin >> x; // Get user input from the keyboard
    } else {
        x = inputs[inputPointerIndex];
        inputPointerIndex++;
    }
    int parameter1 = memory[instructionPointer+1];
    memory[parameter1] = x;
    return 2;
}

int IntcodeComputer::calcResultOpcode4(bool modeParam1) {
    int parameter1 = memory[instructionPointer+1];
    int value1 = (modeParam1) ? parameter1 : memory[parameter1];
   // sleep(1);
    //std::cout << "Output: " << value1 << std::endl;
    lastOutputtedValue = value1;
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

void IntcodeComputer::calculate() {
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
            if (inputPointerIndex > inputs.size()){
                return; // return and wait for new input
            }
            instructionPointer += calcResultOpcode3();
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
            instructionPointer += calcResultOpcode7(modeParam1, modeParam2);
        }
        else if (opcode == 8) {
            instructionPointer += calcResultOpcode8(modeParam1, modeParam2);
        }
       
        opcode = memory[instructionPointer];
        
    }
    return;
}

int IntcodeComputer::getResultFromAddress(int resultAddress) { 
    instructionPointer = 0;
    calculate();
    return memory[resultAddress];
}

int IntcodeComputer::getOutputUsingInput(std::vector<int> input) {
    if (memory[instructionPointer] != 99) {
        inputs = input;
        calculate();
        return lastOutputtedValue;
    }
    return -1;
}

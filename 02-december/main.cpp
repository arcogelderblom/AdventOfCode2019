#include "OpcodeCalculator.hpp"
#include "FileLoader.hpp"

#include <iostream>

int main() {
    OpcodeCalculator calculator;
    FileLoader fileLoader;
    std::vector<std::string> codes = fileLoader.getCommaSeparatedVectorFromFile("02-december/input.txt");
    std::vector<int> opcode;
    for (std::string code : codes) {
        opcode.push_back(std::stoi(code));
    }

    // initial setup
    opcode[1] = 12;
    opcode[2] = 2;
    std::cout << "Result for puzzle one: " << calculator.calculateOpcode(opcode, 0) << std::endl;
    return 0;
}
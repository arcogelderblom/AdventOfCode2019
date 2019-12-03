#include "IntcodeComputer.hpp"
#include "FileLoader.hpp"

#include <iostream>

int main() {
    FileLoader fileLoader;
    std::vector<std::string> codes = fileLoader.getCommaSeparatedVectorFromFile("02-december/input.txt");
    std::vector<int> program;
    for (std::string code : codes) {
        program.push_back(std::stoi(code));
    }

    // initial setup
    program[1] = 12;
    program[2] = 2;

    IntcodeComputer computer(program);
    std::cout << "Result for puzzle one: " << computer.getResultFromAddress(0) << std::endl;
    return 0;
}
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

    int noun = 0;
    int verb = 0;
    int result = 0;
    int expectedResult = 19690720;
    do {
        program[1] = noun;
        program[2] = verb;
        IntcodeComputer computer2(program);
        result = computer2.getResultFromAddress(0);

        if (noun < 99) {
            noun++;
        } else {
            noun = 0;
            verb ++;
        }
    } while (result != expectedResult);
    
    std::cout << "Result for puzzle two: " << (100 * program[1]) + program[2] << std::endl;
    return 0;
}
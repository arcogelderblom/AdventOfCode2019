#include "FileLoader.hpp"
#include "IntcodeComputer.hpp"

#include <iostream>

int main() {
    FileLoader fileLoader;
    std::vector<std::string> codes = fileLoader.getCommaSeparatedVectorFromFile("05-december/input.txt");
    std::vector<int> program;
    for (std::string code : codes) {
        program.push_back(std::stoi(code));
    }
    
    IntcodeComputer intcodeComputer(program);
    intcodeComputer.getResultFromAddress(0);
    std::cout << "Read the result to puzzle one from the command line." << std::endl;
    
    return 0;
}

#include "FileLoader.hpp"
#include "IntcodeComputer.hpp"

#include <iostream>

int main() {
    FileLoader fileLoader;
    std::vector<std::string> codes = fileLoader.getCommaSeparatedVectorFromFile("09-december/input.txt");
    std::vector<long> program;
    for (std::string code : codes) {
        program.push_back(std::stol(code));
    }
    
    IntcodeComputer intcodeComputer(program);
    std::vector<int> inputs = {1};
    std::cout << "The result for puzzle one is: " << intcodeComputer.getOutputUsingInput(inputs) << std::endl;
    IntcodeComputer intcodeComputer2(program);
    std::vector<int> inputs2 = {2};
    std::cout << "The result for puzzle two is: " << intcodeComputer2.getOutputUsingInput(inputs2) << std::endl;
    return 0;
}

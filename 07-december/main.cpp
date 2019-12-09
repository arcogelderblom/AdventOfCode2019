#include "FileLoader.hpp"
#include "AmplificationComputers.hpp"

#include <iostream>

int main() {
    FileLoader fileLoader;
    std::vector<std::string> codes = fileLoader.getCommaSeparatedVectorFromFile("07-december/input.txt");
    std::vector<int> program;
    for (std::string code : codes) {
        program.push_back(std::stoi(code));
    }
    
    AmplificationComputers amplifiers;
    std::vector<std::vector<int> > possibleInputs = amplifiers.calculatePossibleInputs(0, 4);
    std::cout << "The result for puzzle one is: " << amplifiers.getMaxThrusterSignalPuzzle1(program, possibleInputs) << std::endl;
    
    std::vector<std::vector<int> > possibleInputs2 = amplifiers.calculatePossibleInputs(5, 9);
    std::cout << "The result for puzzle two is: " << amplifiers.getMaxThrusterSignalPuzzle2(program, possibleInputs2) << std::endl;
    
    return 0;
}

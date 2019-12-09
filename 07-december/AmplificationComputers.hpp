#pragma once

#include <vector>

class AmplificationComputers {
    public:
        std::vector<std::vector<int> > calculatePossibleInputs(int lowest, int highest);
        int getMaxThrusterSignalPuzzle1(std::vector<int> program, std::vector<std::vector<int> > inputOptions);
        int getMaxThrusterSignalPuzzle2(std::vector<int> program, std::vector<std::vector<int> > inputOptions);
};
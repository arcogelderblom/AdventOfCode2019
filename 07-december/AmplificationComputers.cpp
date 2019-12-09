#include "AmplificationComputers.hpp"

#include "IntcodeComputer.hpp"

std::vector<std::vector<int> > AmplificationComputers::calculatePossibleInputs(int lowest, int highest) {
    std::vector<int> possibleInputs;
    for (int i = lowest; i <= highest; i++) {
        possibleInputs.push_back(i);
    }
    std::vector<std::vector<int> > options;
    
    std::vector<int> input{0,0,0,0,0};
    for (int num0 : possibleInputs) {
        input[0] = num0;
        for (int num1 : possibleInputs) {
            if (num1 != num0) {
                input[1] = num1;
                for (int num2 : possibleInputs) {
                    if (num2 != num1 && num2 != num0) {
                        input[2] = num2;
                        for (int num3 : possibleInputs) {
                            if (num3 != num2 && num3 != num1 && num3 != num0) {
                                input[3] = num3;
                                for (int num4 : possibleInputs) {
                                    if (num4 != num3 && num4 != num2 && num4 != num1 && num4 != num0) {
                                        input[4] = num4;
                                        options.push_back(input);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return options;
}

int AmplificationComputers::getMaxThrusterSignalPuzzle1(std::vector<int> program, std::vector<std::vector<int> > inputOptions) {
    int highestOutput = 0;
    for (std::vector<int> inputs : inputOptions) {
        int output = 0;
        IntcodeComputer amplifierA(program);
        std::vector<int> input = {inputs[0],0};
        output = amplifierA.getOutputUsingInput(input);

        input = {inputs[1], output};
        IntcodeComputer amplifierB(program);
        output = amplifierB.getOutputUsingInput(input);

        input = {inputs[2], output};
        IntcodeComputer amplifierC(program);
        output = amplifierC.getOutputUsingInput(input);

        input = {inputs[3], output};
        IntcodeComputer amplifierD(program);
        output = amplifierD.getOutputUsingInput(input);

        input = {inputs[4], output};
        IntcodeComputer amplifierE(program);
        output = amplifierE.getOutputUsingInput(input);
        if (output > highestOutput) {
            highestOutput = output;
        }
    }
    return highestOutput;
}

int AmplificationComputers::getMaxThrusterSignalPuzzle2(std::vector<int> program, std::vector<std::vector<int> > inputOptions) {
    int highestOutput = 0;

    for (std::vector<int> inputs : inputOptions) {
        int output = 0;

        IntcodeComputer amplifierA(program);
        IntcodeComputer amplifierB(program);
        IntcodeComputer amplifierC(program);
        IntcodeComputer amplifierD(program);
        IntcodeComputer amplifierE(program);

        std::vector<int> inputA = {inputs[0]};
        std::vector<int> inputB = {inputs[1]};
        std::vector<int> inputC = {inputs[2]};
        std::vector<int> inputD = {inputs[3]};
        std::vector<int> inputE = {inputs[4]};

        while(1) {
            inputA.push_back(output);
            output = amplifierA.getOutputUsingInput(inputA);
            inputB.push_back(output);
            output = amplifierB.getOutputUsingInput(inputB);
            inputC.push_back(output);
            output = amplifierC.getOutputUsingInput(inputC);
            inputD.push_back(output);
            output = amplifierD.getOutputUsingInput(inputD);
            inputE.push_back(output);
            output = amplifierE.getOutputUsingInput(inputE);

            if (output > highestOutput) {
                highestOutput = output;
            }
            else if (output == -1) { 
                break;
            }
        }
    }
    return highestOutput;
}
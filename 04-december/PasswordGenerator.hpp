#pragma once

#include <vector>

class PasswordGenerator {
    private:
        bool checkDescendingNumbers(std::vector<int> password);
        bool checkDoubleNumbers(std::vector<int> password);
        bool checkDoubleNumbers2(std::vector<int> password);
    public:
        std::vector<int> getVectorFromInt(int password);
        bool isValidPassword1(std::vector<int> password);
        bool isValidPassword2(std::vector<int> password);
        std::vector< std::vector<int> > getPossiblePasswords(int lowest, int highest, int puzzleNum);
};
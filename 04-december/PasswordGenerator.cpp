#include "PasswordGenerator.hpp"
#include <iostream>
bool PasswordGenerator::checkDescendingNumbers(std::vector<int> password) {
    for (int i = 0; i < password.size()-1; i++) {
        if (password[i+1] < password[i]) {
            return true;
        }
    }
    return false;
}

bool PasswordGenerator::checkDoubleNumbers(std::vector<int> password) {
    for (int i = 0; i < password.size()-1; i++) {
        if (password[i] == password[i+1]) {
            return true;
        }
    }
    return false;
}

bool PasswordGenerator::checkDoubleNumbers2(std::vector<int> password) {
    for (int i = 0; i < password.size()-1; i++) {
        if (password[i] == password[i+1] && password[i] != password[i+2]) {
            return true;
        } else {
            while(password[i] == password[i+1]) {
                i++;
            }
        }
    }
    return false;
}

bool PasswordGenerator::isValidPassword1(std::vector<int> password) {
    return (password.size() == 6 && !checkDescendingNumbers(password) && checkDoubleNumbers(password));
}

bool PasswordGenerator::isValidPassword2(std::vector<int> password) {
    return (password.size() == 6 && !checkDescendingNumbers(password) && checkDoubleNumbers2(password));
}

std::vector<int> PasswordGenerator::getVectorFromInt(int password) {
    std::vector<int> result;
    int factor = 100000;
    
    while(factor > 0) {
        int value = password / factor;
        result.push_back(value);
        password -= (value*factor);
        factor /= 10;
    }
    return result;
}

std::vector< std::vector<int> > PasswordGenerator::getPossiblePasswords(int lowest, int highest, int puzzleNum) {
    std::vector< std::vector<int> > result;
    
    for (int i = lowest; i <= highest; i++) {
        std::vector<int> password = getVectorFromInt(i);
        if (puzzleNum == 1) {
            if (isValidPassword1(password)) {
                result.push_back(password);
            }
        } else {
            if (isValidPassword2(password)) {
                result.push_back(password);
            }
        }
    }

    return result;
}
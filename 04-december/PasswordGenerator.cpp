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

bool PasswordGenerator::isValidPassword(std::vector<int> password) {
    return (password.size() == 6 && !checkDescendingNumbers(password) && checkDoubleNumbers(password));
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

std::vector< std::vector<int> > PasswordGenerator::getPossiblePasswords(int lowest, int highest) {
    std::vector< std::vector<int> > result;
    int amount = 0;
    for (int i = lowest; i <= highest; i++) {
        std::vector<int> password = getVectorFromInt(i);
        if (isValidPassword(password)) {
            amount++;
            result.push_back(password);
        }
    }

    return result;
}
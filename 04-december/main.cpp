#include "PasswordGenerator.hpp"

#include <iostream>

int main() {
    PasswordGenerator generator;
    std::vector< std::vector<int> > passwords = generator.getPossiblePasswords(146810, 612564);

    std::cout << "The result for puzzle one is: " << passwords.size() << std::endl;
    return 0;
}

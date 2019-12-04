#include "PasswordGenerator.hpp"

#include <iostream>

int main() {
    PasswordGenerator generator;
    std::vector< std::vector<int> > passwords1 = generator.getPossiblePasswords(146810, 612564, 1);
    std::vector< std::vector<int> > passwords2 = generator.getPossiblePasswords(146810, 612564, 2);

    std::cout << "The result for puzzle one is: " << passwords1.size() << std::endl;
    std::cout << "The result for puzzle two is: " << passwords2.size() << std::endl;
    return 0;
}

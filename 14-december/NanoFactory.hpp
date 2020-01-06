#pragma once

#include <vector>
#include <string>
#include <map>

struct Reaction {
    std::vector< std::pair<int, std::string> > input;
    std::pair<int, std::string> output;
};

class NanoFactory {
    private:
        std::map<std::string, double> materialsNeeded;
        std::map<std::string, double> inventory;
    public:
        std::vector<Reaction> parse(std::vector<std::string> chemicalReactions);
        void calculateMaterialsNeeded(std::vector<Reaction> reactions, std::string outputType, double amount);
        long long getAmountOfOre(std::vector<Reaction> reactions);
        long long getFuel(std::vector<Reaction> reactions, long long ore);
};
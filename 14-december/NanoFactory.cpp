#include "NanoFactory.hpp"

#include <iostream>
#include <cmath>

std::vector<Reaction> NanoFactory::parse(std::vector<std::string> chemicalReactions) {
    std::vector<Reaction> result;
    for (std::string reaction : chemicalReactions) {
        Reaction chemicalReaction;
        std::string input = reaction.substr(0, reaction.find(" => "));
        if (std::count(input.begin(), input.end(), ',') > 0) {
            int amountOfInputs = std::count(input.begin(), input.end(), ',');
            for (int i = 0; i <= amountOfInputs; i++) {
                if (i == amountOfInputs) {
                    std::string parsed = input.substr(0, input.find(", "));
                    int inputAmount = std::stoi(parsed.substr(0, parsed.find(' ')));
                    std::string inputType = parsed.substr(parsed.find(' ') + 1);
                    chemicalReaction.input.push_back(std::make_pair(inputAmount, inputType));
                } else {
                    std::string parsed = input.substr(0, input.find(", "));
                    int inputAmount = std::stoi(parsed.substr(0, parsed.find(' ')));
                    std::string inputType = parsed.substr(parsed.find(' ') + 1);
                    chemicalReaction.input.push_back(std::make_pair(inputAmount, inputType));
                    input = input.substr(input.find(", ") + std::string(", ").size());
                }
            }
        } else if (std::count(input.begin(), input.end(), ',') == 0) {
            int input1Amount = std::stoi(input.substr(0, input.find(' ')));
            std::string input1Type = input.substr(input.find(' ') + 1);
            chemicalReaction.input.push_back(std::make_pair(input1Amount, input1Type));
        }
        std::string output = reaction.substr(reaction.find(" => ") + std::string(" => ").size());
        int outputAmount = std::stoi(output.substr(0, output.find(' ')));
        std::string outputType = output.substr(output.find(' ') + 1);
        chemicalReaction.output = std::make_pair(outputAmount, outputType);
        
        result.push_back(chemicalReaction);
    }
    return result;
}

void NanoFactory::calculateMaterialsNeeded(std::vector<Reaction> reactions, std::string outputType, double amount) {
    for (Reaction reaction : reactions) {
        if (reaction.output.second == outputType) { 
            if (inventory[outputType] - materialsNeeded[outputType] - amount > 0) {
                materialsNeeded[outputType] += double(amount);
                return; // already enough made
            }
            if (inventory[outputType] - materialsNeeded[outputType] > 0) {
                double amountNeeded = amount;
                amount -= inventory[outputType] - materialsNeeded[outputType]; // correct amount to make with what is in the inventory
                materialsNeeded[outputType] += double(amountNeeded);
            } else {
                materialsNeeded[outputType] += double(amount);
            }

            if (fmod(amount, double(reaction.output.first)) != 0) {
                long long tmp = amount - fmod(amount, double(reaction.output.first));
                inventory[outputType] += tmp + reaction.output.first;
            } 
            else {
                inventory[outputType] += double(amount);
            }
            
            for (auto input : reaction.input) {
                double times = ceil(amount / double(reaction.output.first));
                calculateMaterialsNeeded(reactions, input.second, double(input.first)*times);
            }
        }
    }
    return;
}

long long NanoFactory::getAmountOfOre(std::vector<Reaction> reactions) {
    long long oreNeeded = 0;

    for (auto material : inventory) {
        for (Reaction reaction : reactions) {
            if (reaction.output.second == material.first && reaction.input[0].second == "ORE") {
                if (fmod(material.second, double(reaction.output.first)) == 0) {
                    oreNeeded += ceil(double(reaction.input[0].first) * (material.second / double(reaction.output.first)));
                }
                else {
                    long long tmp = material.second - fmod(material.second, double(reaction.output.first));
                    oreNeeded += ceil(double(reaction.input[0].first) * (tmp / double(reaction.output.first))) + reaction.input[0].first;
                }
            }
        }
    }
    return oreNeeded;
}

long long NanoFactory::getFuel(std::vector<Reaction> reactions, long long ore) {
    // clear inventories in case they were filled
    materialsNeeded.clear();
    inventory.clear();

    calculateMaterialsNeeded(reactions, "FUEL", 100);
    long long oreForOneFuel = getAmountOfOre(reactions);

    materialsNeeded.clear();
    inventory.clear();
    calculateMaterialsNeeded(reactions, "FUEL", 101);
    long long difference = std::abs(getAmountOfOre(reactions) - oreForOneFuel);
    long long fuel = ore / difference;
    
    while (getAmountOfOre(reactions) < (ore - (ore/100000)) || getAmountOfOre(reactions) > (ore + (ore/100000)) ) {
        materialsNeeded.clear();
        inventory.clear();
        calculateMaterialsNeeded(reactions, "FUEL", fuel);
        if (getAmountOfOre(reactions) > ore) {
            fuel -= (getAmountOfOre(reactions) - ore) / difference;
        }
        else {
            fuel += (ore - getAmountOfOre(reactions)) / difference;
        }
    }

    // calculate the exact fuel
    if (getAmountOfOre(reactions) > ore) {
        while(getAmountOfOre(reactions) > ore) {
            materialsNeeded.clear();
            inventory.clear();
            calculateMaterialsNeeded(reactions, "FUEL", --fuel);
        }
    }
    else {
        while(getAmountOfOre(reactions) < ore) {
            materialsNeeded.clear();
            inventory.clear();
            calculateMaterialsNeeded(reactions, "FUEL", ++fuel);
        }
        fuel -= 1; // apply correction
    }
   
    return fuel;
}

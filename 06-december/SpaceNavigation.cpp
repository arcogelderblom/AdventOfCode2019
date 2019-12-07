#include "SpaceNavigation.hpp"

SpaceNavigation::SpaceNavigation(std::vector<std::string> map) :
    map(map)
{}

void SpaceNavigation::discoverOrbits() {
    for (std::string mapEntry : map) {
        std::string firstObjectName = mapEntry.substr(0, mapEntry.find(")"));
        std::string secondObjectName = mapEntry.substr(mapEntry.find(")")+1);
        bool firstObjectExists = false;
        bool secondObjectExists = false;
        Object * firstObject = new Object;
        Object * secondObject = new Object;
        for (Object * o : objects) {
            if (firstObjectName == o->name) {
                firstObjectExists = true;
                firstObject = o;
            }
            if (secondObjectName == o->name) {
                secondObjectExists = true;
                secondObject = o;
            }
        }
        if (!firstObjectExists) {
            firstObject->name = firstObjectName;
            objects.push_back(firstObject);
        }
        if (!secondObjectExists) {
            secondObject->name = secondObjectName;
            objects.push_back(secondObject);
        }
        secondObject->orbitsObject = firstObject;
    }
}

int SpaceNavigation::totalOrbits() {
    discoverOrbits();
    
    int result = 0;
    for (Object * o : objects) {
        int amountOfOrbitsObject = 0;
        Object * currentObject = o;
        while(currentObject->name != "COM") {
            amountOfOrbitsObject++;
            currentObject = currentObject->orbitsObject;
        }
        result += amountOfOrbitsObject;
    }

    return result;
}

int SpaceNavigation::getMinOrbitalTransfers(const std::string object1Name, const std::string object2Name) {
    discoverOrbits();
    
    Object * firstObject;
    Object * secondObject;
    for (Object * o : objects) {
        if (o->name == object1Name) {
            firstObject = o;
        }
        if (o->name == object2Name) {
            secondObject = o;
        }
    }

    std::vector<std::string> pathObject1;
    std::vector<std::string> pathObject2;
    while(firstObject->name != "COM") {
        firstObject = firstObject->orbitsObject;
        pathObject1.push_back(firstObject->name);
    }
    while(secondObject->name != "COM") {
        secondObject = secondObject->orbitsObject;
        pathObject2.push_back(secondObject->name);
    }

    for (int i = 0; i < pathObject1.size(); i++) {
        for (int j = 0; j < pathObject1.size(); j++) {
            if (pathObject1[i] == pathObject2[j]) {
                return i+j;
            }
        }
    }

    return 0;
}

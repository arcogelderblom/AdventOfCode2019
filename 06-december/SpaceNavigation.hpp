#pragma once

#include <vector>
#include <string>

struct Object {
    std::string name;
    Object * orbitsObject;
};

class SpaceNavigation {
    private:
        std::vector<std::string> map;
        std::vector<Object *> objects;
        void discoverOrbits();
    public:
        SpaceNavigation(std::vector<std::string> map);
        int totalOrbits();
};
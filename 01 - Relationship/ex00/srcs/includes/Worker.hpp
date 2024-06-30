#pragma once 

#include "Tool.hpp"
#include "Workshop.hpp"

#include <iostream>
#include <map>

class Tool;
class Workshop;

struct  Position {
    float   x;
    float   y;

    Position(float x_val, float y_val) : x(x_val), y(y_val) {}
};

struct  Statistic {
    int level;
    int exp;

    Statistic(int level_val, int exp_val) : level(level_val), exp(exp_val) {}
};

class Worker { 

    public:
        Worker(float x, float y, int level, int exp);
        ~Worker();

        void AmIEquiped(Tool *tool);
        void equipTool(Tool *tool);
        void unequipTool(Tool *tool);

        std::map<std::string, Tool *> getTools() const;

    private:
        Position                coordonnee;
        Statistic               stat;

        std::map<std::string, Tool *>   tools;
};
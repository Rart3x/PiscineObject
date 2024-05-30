#pragma once 

#include "Tool.hpp"
#include "Workshop.hpp"

#include <iostream>
#include <list>

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

        void    equipTool(Tool* tool);
        void    desequipTool();
        void    useTool();

        void    work();

        void    addWorkshop(Workshop *workshop);
        void    deleteWorkshop(Workshop* workshop);
        bool    isInWorkshop(Workshop* workshop);

    private:
        Position                coordonnee;
        Statistic               stat;
        Tool                    *tool;

        std::list<Workshop *>   workshops;
};
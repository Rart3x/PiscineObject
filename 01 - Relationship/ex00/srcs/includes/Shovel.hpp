#pragma once

#include "Tool.hpp"

#include <iostream>

class Shovel : public Tool {

    public:
        Shovel();
        ~Shovel();

        void        use();

        void        printEquiped();

        std::string getStr() const;
        Worker*     getWorker();

        void        setWorker(Worker* worker);
        void        setEquiped();

    private:
        bool            isEquiped;
        unsigned int    numberOfUses;

        std::string     str;

        Worker  *worker;
};
#pragma once

#include "Tool.hpp"

#include <iostream>

class Shovel : public Tool {

    public:
        Shovel();
        ~Shovel();

        void        use();

        void        incrementUses();
        void        printEquiped();

        Worker*     getWorker();
        
        void        setWorker(Worker* worker);
        void        setEquiped();

    private:
        bool            isEquiped;
        unsigned int    numberOfUses;

        Worker  *worker;
};
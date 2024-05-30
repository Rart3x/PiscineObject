#pragma once

#include "Tool.hpp"

#include <iostream>

class Hammer : public Tool {

    public:
        Hammer();
        ~Hammer();

        void        use();

        void        printEquiped();
        void        incrementUses();

        Worker*     getWorker();
        
        void        setWorker(Worker* worker);
        void        setEquiped();

    private:
        bool    isEquiped;
        int     numberOfUses;

        Worker  *worker;
};
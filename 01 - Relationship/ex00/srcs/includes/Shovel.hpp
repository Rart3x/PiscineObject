#pragma once

#include "Tool.hpp"

#include <iostream>

class Shovel : public Tool {

    public:
        Shovel();
        ~Shovel();

        void    use();

        void        printEquiped();

        Worker*     getWorker();
        
        void        setWorker(Worker* worker);
        void        setEquiped();

    private:
        bool    isEquiped;
        Worker  *worker;
};
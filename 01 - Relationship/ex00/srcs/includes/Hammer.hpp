#pragma once

#include "Tool.hpp"

#include <iostream>

class Hammer : public Tool {

    public:
        Hammer();
        ~Hammer();

        void        use();

        void        printEquiped();

        std::string getStr() const;
        Worker*     getWorker();
        
        void        setWorker(Worker* worker);
        void        setEquiped();

    private:
        bool        isEquiped;
        int         numberOfUses;

        std::string str;

        Worker  *worker;
};
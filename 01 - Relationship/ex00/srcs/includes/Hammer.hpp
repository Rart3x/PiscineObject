#pragma once

#include "Tool.hpp"

#include <iostream>

class Hammer : public Tool {

    public:
        Hammer();
        ~Hammer();

        void        use();

        void        printEquiped();
        void        printNumberOfUses();

        std::string getStr() const;
        Worker*     getWorker();
        
        void        setWorker(Worker* worker);
        void        setEquiped();

    private:
        bool            isEquiped;
        size_t          numberOfUses;

        std::string     str;

        Worker          *worker;
};
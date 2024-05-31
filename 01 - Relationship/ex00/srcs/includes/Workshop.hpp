#pragma once 

#include "Worker.hpp"

#include <iostream>
#include <list>

class Worker;

class Workshop {
    public:
        Workshop(std::string toolNeeded);
        ~Workshop();

        void addWorker(Worker* worker);
        void deleteWorker(Worker* worker);

        bool isWorker(Worker* worker);

        void executeWorkDay();

        std::string getToolNeeded() const;

    private:
        std::list<Worker *> workers;
        std::string toolNeeded;
};
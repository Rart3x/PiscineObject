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

        void executeWorkDay();
        bool isWorkerInWorkshop(Worker* worker);

        std::string getToolNeeded() const;
        std::list<Worker *> getWorkers() const;

    private:
        std::string toolNeeded;

        std::list<Worker *> workers;
};
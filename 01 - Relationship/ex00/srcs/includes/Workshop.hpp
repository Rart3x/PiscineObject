#pragma once 

#include "Worker.hpp"

#include <iostream>
#include <list>

class Worker;

class Workshop {
    public:
        Workshop();
        ~Workshop();

        void addWorker(Worker* worker);
        void deleteWorker(Worker* worker);

        bool isWorker(Worker* worker);

    private:
        std::list<Worker *> workers;        
};
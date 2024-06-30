#include "../includes/Workshop.hpp"

Workshop::Workshop(std::string toolNeeded) : toolNeeded(toolNeeded) {}

Workshop::~Workshop() {
    // for (std::list<Worker *>::iterator it = workers.begin(); it != workers.end(); it++) {
    //     (*it)->deleteWorkshop(this);
    // }
    // workers.clear();
}

void Workshop::addWorker(Worker* worker) {
    if (worker) {
        if (this->toolNeeded != "") {

            if (worker->isWorkerHaveTool(this->toolNeeded) == false) {
                std::cout << "Worker doesn't have the required tool" << std::endl;
                return;
            }

            if (isWorkerInWorkshop(worker)) {
                std::cout << "Worker already in the workshop" << std::endl;
                return;
            }

            workers.push_back(worker);

            std::cout << "Worker added to the workshop" << std::endl;
        }
        else 
            std::cout << "Worker doesn't have the required tool" << std::endl;
    }
    else
        std::cout << "Worker is NULL" << std::endl;
}

void Workshop::deleteWorker(Worker* worker) {
    if (worker) {
        if (!isWorkerInWorkshop(worker)) {
            std::cout << "Worker not in the workshop" << std::endl;
            return;
        }
        workers.remove(worker);

        std::cout << "Worker removed from the workshop" << std::endl;
    }
    else
        std::cout << "Worker is NULL" << std::endl;
}

void Workshop::executeWorkDay() {
    for (std::list<Worker *>::iterator it = workers.begin(); it != workers.end(); it++) {
        (*it)->work();
    }
}

bool Workshop::isWorkerInWorkshop(Worker* worker) {
    for (std::list<Worker *>::iterator it = workers.begin(); it != workers.end(); it++) {
        if (*it == worker) {
            return true;
        }
    }
    return false;
}

std::string Workshop::getToolNeeded() const {
    return this->toolNeeded;
}

std::list<Worker *> Workshop::getWorkers() const {
    return this->workers;
}
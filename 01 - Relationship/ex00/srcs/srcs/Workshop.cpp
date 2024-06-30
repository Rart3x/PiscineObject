#include "../includes/Workshop.hpp"

Workshop::Workshop(std::string toolNeeded) : toolNeeded(toolNeeded) {}

Workshop::~Workshop() {
}

void Workshop::addW(Worker *worker) {
    if (worker) {
        this->workers.push_back(worker);
        std::cout << "Worker added to the workshop" << std::endl;
    }
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

            this->addW(worker);
            worker->addW(this);
        }
        else 
            std::cout << "Worker doesn't have the required tool" << std::endl;
    }
    else
        std::cout << "Worker is NULL" << std::endl;
}

void    Workshop::deleteW(Worker *worker) {
    if (worker) {
        this->workers.remove(worker);
        std::cout << "Worker removed from the workshop" << std::endl;
    }
}

void Workshop::deleteWorker(Worker* worker) {
    if (worker) {
        if (!isWorkerInWorkshop(worker)) {
            std::cout << "Worker not in the workshop" << std::endl;
            return;
        }
        worker->deleteW(this);
        this->deleteW(worker);
    }
    else
        std::cout << "Worker is NULL" << std::endl;
}

void Workshop::executeWorkDay() {
    for (std::list<Worker *>::iterator it = workers.begin(); it != workers.end(); it++)
        (*it)->work();
}

bool Workshop::isWorkerInWorkshop(Worker* worker) {
    for (std::list<Worker *>::iterator it = workers.begin(); it != workers.end(); it++) {
        if (*it == worker)
            return true;
    }
    return false;
}

std::string Workshop::getToolNeeded() const {
    return this->toolNeeded;
}

std::list<Worker *> Workshop::getWorkers() const {
    return this->workers;
}
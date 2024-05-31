#include "../includes/Workshop.hpp"

Workshop::Workshop(std::string toolNeeded) : toolNeeded(toolNeeded) {}
Workshop::~Workshop() {}

void    Workshop::addWorker(Worker* worker) {
    if (worker) {
        if (!isWorker(worker)) {
            if (worker->getEquipedTool() && worker->getEquipedTool()->getStr() == this->toolNeeded) {
                this->workers.push_back(worker);
                worker->addWorkshop(this);
                std::cout << "Registered a Worker" << std::endl;
            }
            else std::cout << "Worker has not good Tool" << std::endl;            
        }
        else std::cout << "Already registered as worker" << std::endl;
    }
    else std::cout << "Error: Cannot register NULL worker" << std::endl;
}

void Workshop::deleteWorker(Worker* worker) {
    if (worker) {
        if (isWorker(worker)) {
            for (std::list<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++) {
                if (*it == worker) {
                    this->workers.erase(it);
                    worker->deleteWorkshop(this);
                    std::cout << "Deleted a Worker" << std::endl;
                    break;
                }
            }
        }
        else std::cout << "Not registered as worker" << std::endl;
    }
    else std::cout << "Error: Cannot delete NULL worker" << std::endl;
}

bool    Workshop::isWorker(Worker* worker) {
    if (worker) {
        for (std::list<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); ++it) {
            if (*it == worker) {
                std::cout << "This worker is IN the workshop" << std::endl;
                return true;
            }
        }
    }
    else std::cout << "Error: Cannot check NULL worker" << std::endl;
    
    std::cout << "This worker is NOT in the workshop" << std::endl;
    return false;
}

void    Workshop::executeWorkDay() {
    size_t i = 0;

    for (std::list<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); ++it) {
        std::cout << "Workday for Worker : " << i << std::endl;
        (*it)->work();
        i++;
    }
}

std::string Workshop::getToolNeeded() const {
    return this->toolNeeded;
}
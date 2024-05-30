#include "../includes/Workshop.hpp"

Workshop::Workshop() {}
Workshop::~Workshop() {}

void    Workshop::addWorker(Worker* worker) {
    if (worker) {
        if (!isWorker(worker)) {
            if (worker) {
                this->workers.push_back(worker);
                worker->addWorkshop(this);
                std::cout << "Registered a Worker" << std::endl;
            }
        }
        else std::cout << "Already registered as worker" << std::endl;
    }
    else std::cout << "Error: Cannot register NULL worker" << std::endl;
}

void Workshop::deleteWorker(Worker* worker) {
    if (worker) {
        if (isWorker(worker)) {
            if (worker) {
                for (std::list<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); ++it) {
                    if (*it == worker) {
                        this->workers.erase(it);
                        std::cout << "Deleted a Worker" << std::endl;
                        worker->deleteWorkshop(this);
                        break;
                    }
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
            if (*it == worker)
                return true;
        }
    }
    else std::cout << "Error: Cannot check NULL worker" << std::endl;
    
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
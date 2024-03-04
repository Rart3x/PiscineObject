#include "../includes/Workshop.hpp"

Workshop::Workshop() {}
Workshop::~Workshop() {}

void    Workshop::addWorker(Worker* worker) {
    if (!isWorker(worker)) {
        if (worker) {
            this->workers.push_back(worker);
            worker->addWorkshop(this);
            std::cout << "Registered a Worker" << std::endl;
        }
    }
    else std::cout << "Already registered as worker" << std::endl;
}

void Workshop::deleteWorker(Worker* worker) {
    if (isWorker(worker)) {
        if (worker) {
            for (std::list<Worker *>::iterator it = workers.begin(); it != workers.end(); ++it) {
                if (*it == worker) {
                    *(it) = NULL;
                    std::cout << "Deleted a Worker" << std::endl;
                    worker->deleteWorkshop(this);
                    break;
                }
            }
        }
    }
    else std::cout << "Not registered as worker" << std::endl;
}

bool    Workshop::isWorker(Worker* worker) {
    for (std::list<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); ++it) {
        if (*it == worker)
            return true;
    }
    return false;
}
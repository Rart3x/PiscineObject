#include "../includes/Shovel.hpp"

Shovel::Shovel() : Tool(), isEquiped(false), worker(NULL) {}
Shovel::~Shovel() {}

void    Shovel::use() {
    std::cout << " << Digging >> " << std::endl;
}

void    Shovel::printEquiped() {
    if (this->isEquiped)
        std::cout << "I am equiped [SHOVEL]" << std::endl;
    else
        std::cout << "I am not equiped [SHOVEL]" << std::endl;
}

Worker* Shovel::getWorker() {
    if (this->worker)
        return this->worker;
    return NULL;
}

void    Shovel::setWorker(Worker *worker) {
    this->worker = worker;
}

void    Shovel::setEquiped() {
    this->isEquiped = !this->isEquiped;
}
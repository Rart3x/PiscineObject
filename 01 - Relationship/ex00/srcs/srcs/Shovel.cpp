#include "../includes/Shovel.hpp"

Shovel::Shovel() : Tool(), isEquiped(false), numberOfUses(0), worker(NULL) {}
Shovel::~Shovel() {}

void    Shovel::use() {
    std::cout << " << Digging [SHOVEL] >> " << std::endl;
}

void    Shovel::printEquiped() {
    if (this->isEquiped)
        std::cout << "I am equiped [SHOVEL]" << std::endl;
    else
        std::cout << "I am not equiped [SHOVEL]" << std::endl;
}

void    Shovel::incrementUses() {
    this->numberOfUses++;
}

Worker* Shovel::getWorker() {
    if (this->worker)
        return this->worker;
    return NULL;
}

void    Shovel::setWorker(Worker *worker) {
    if (worker)
        this->worker = worker;
    else std::cout << "Error: Cannot set NULL worker" << std::endl;
}

void    Shovel::setEquiped() {
    this->isEquiped = !this->isEquiped;
}
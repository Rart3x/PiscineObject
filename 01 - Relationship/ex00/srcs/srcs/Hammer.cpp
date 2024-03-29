#include "../includes/Hammer.hpp"

Hammer::Hammer() : Tool(), isEquiped(false), worker(NULL) {}
Hammer::~Hammer() {}

void    Hammer::use() {
    std::cout << " << Smash >> " << std::endl;
}

void    Hammer::printEquiped() {
    if (this->isEquiped)
        std::cout << "I am equiped [HAMMER]" << std::endl;
    else
        std::cout << "I am not equiped [HAMMER]" << std::endl;
}

Worker* Hammer::getWorker() {
    if (this->worker)
        return this->worker;
    return NULL;
}

void    Hammer::setWorker(Worker *worker) {
    this->worker = worker;
}

void    Hammer::setEquiped() {
    this->isEquiped = !this->isEquiped;
}
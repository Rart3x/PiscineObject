#include "../includes/Hammer.hpp"

Hammer::Hammer() : Tool(), isEquiped(false), numberOfUses(0), str("Hammer"), worker(NULL) {}
Hammer::~Hammer() {
    if (this->getWorker()) {
        this->getWorker()->desequipTool();
        this->worker = NULL;
    }
}

void    Hammer::use() {
    std::cout << " << Smash [HAMMER] >> " << std::endl;
    this->numberOfUses++;
}

void    Hammer::printEquiped() {
    if (this->isEquiped)
        std::cout << "I am equiped [HAMMER]" << std::endl;
    else
        std::cout << "I am not equiped [HAMMER]" << std::endl;
}

std::string Hammer::getStr() const {
    return this->str;
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
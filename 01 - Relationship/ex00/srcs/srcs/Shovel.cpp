#include "../includes/Shovel.hpp"

Shovel::Shovel() : Tool(), isEquiped(false), numberOfUses(0), str("Shovel"), worker(NULL) {}
Shovel::~Shovel() {
    if (this->getWorker()) {
        this->getWorker()->unequipTool();
        this->worker = NULL;
    }
}

void    Shovel::use() {
    std::cout << " << Digging [SHOVEL] >> " << std::endl;
    this->numberOfUses++;
}

void    Shovel::printEquiped() {
    if (this->isEquiped)
        std::cout << "I am equiped [SHOVEL]" << std::endl;
    else
        std::cout << "I am not equiped [SHOVEL]" << std::endl;
}

std::string Shovel::getStr() const {
    return this->str;
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
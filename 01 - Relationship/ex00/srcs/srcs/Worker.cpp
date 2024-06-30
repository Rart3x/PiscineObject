#include "../includes/Worker.hpp"

Worker::Worker(float x, float y, int level, int exp) : coordonnee(Position(x, y)), stat(Statistic(level, exp)) {
}

Worker::~Worker() {
    for (std::map<std::string, Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++) {
        it->second->setWorker(NULL);
        it->second->setEquiped();
    }
    this->tools.clear();
}

void   Worker::AmIEquiped(Tool *tool) {
    if (tool) {
        if (tool->getWorker() == this) {
            std::cout << "I am equiped by: " << tool->getStr() << std::endl;
            return ;
        }
    }
    std::cout << "I am not equiped by: " << tool->getStr() << std::endl;
}

void    Worker::equipTool(Tool *tool) {
    if (tool) {
        if (tool->getWorker() == NULL) {
            tool->setWorker(this);
            tool->setEquiped();
            this->tools[tool->getStr()] = tool;
        }
        else 
        {
            tool->getWorker()->unequipTool(tool);
            tool->setWorker(this);
            this->tools[tool->getStr()] = tool;
            tool->setEquiped();
        }
        std::cout << "Tool equiped: " << tool->getStr() << std::endl;
    }
    else 
        std::cout << "Tool is NULL cannot equip" << std::endl;
}

void   Worker::unequipTool(Tool *tool) {
    if (tool) {
        if (tool->getWorker() == this) {
            tool->setWorker(NULL);
            tool->setEquiped();
            this->tools.erase(tool->getStr());

            std::cout << "Tool unequiped: " << tool->getStr() << std::endl;
        }
        else 
            std::cout << "Tool is not equiped: " << tool->getStr() << std::endl;
    }
    else 
        std::cout << "Tool is NULL cannot unequip" << std::endl;
}

std::map<std::string, Tool *> Worker::getTools() const {
    return this->tools;
}
#include "../includes/Worker.hpp"

Worker::Worker(float x, float y, int level, int exp) : coordonnee(Position(x, y)), stat(Statistic(level, exp)) {}
Worker::~Worker() {}

void   Worker::AmIEquiped(Tool *tool) {
    if (tool) {
        if (tool->getWorker() == this) {
            std::cout << "I am equiped by: " << tool->getStr() << std::endl;
            return ;
        }
    }
    std::cout << "I am not equiped by: " << tool->getStr() << std::endl;
}

void    Worker::addW(Workshop *workshop) {
    if (workshop) {
        this->workshops.push_back(workshop);
        std::cout << "Workshop added" << std::endl;
    }
}

void   Worker::addWorkshop(Workshop *workshop) {
    if (workshop) {
        if (this->isWorkerHaveTool(workshop->getToolNeeded()) == false) {
            std::cout << "Worker doesn't have the required tool" << std::endl;
            return ;
        }

        if (this->isWorkshopIsInWorker(workshop)) {
            std::cout << "Worker already in the workshop" << std::endl;
            return ;
        }
        this->addW(workshop);
        workshop->addW(this);
    }
    else 
        std::cout << "Workshop is NULL" << std::endl;
}

void    Worker::deleteW(Workshop *workshop) {
    if (workshop) {
        this->workshops.remove(workshop);
        std::cout << "Workshop removed from the worker" << std::endl;
    }
}

void   Worker::deleteWorkshop(Workshop *workshop) {
    if (workshop) {
        if (!this->isWorkshopIsInWorker(workshop)) {
            std::cout << "Worker not in the workshop" << std::endl;
            return ;
        }
        this->deleteW(workshop);
        workshop->deleteW(this);
    }
    else 
        std::cout << "Workshop is NULL" << std::endl;
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
            tool->setEquiped();
            this->tools[tool->getStr()] = tool;
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

            if (workshops.size() > 0) {
                for (std::list<Workshop*>::iterator it = workshops.begin(); it!= workshops.end(); ) {
                    if ((*it)->getToolNeeded() == tool->getStr()) {
                        (*it)->deleteW(this);
                        it = workshops.erase(it);
                    } else
                        ++it;
                }

            }
            std::cout << "Tool unequiped: " << tool->getStr() << std::endl;
        }
        else 
            std::cout << "Tool is not equiped: " << tool->getStr() << std::endl;
    }
    else 
        std::cout << "Tool is NULL cannot unequip" << std::endl;
}

void    Worker::work() const {
    if (workshops.size() > 0)
        std::cout << "I am currently working" << std::endl;
    else
        std::cout << "I can't currently work" << std::endl;
}

bool Worker::isWorkerHaveTool(const std::string &tool) const {
    if (this->tools.find(tool) != this->tools.end())
        return true;
    return false;
}

bool Worker::isWorkshopIsInWorker(Workshop *workshop) const {
    for (std::list<Workshop *>::const_iterator it = this->workshops.begin(); it != this->workshops.end(); it++) {
        if (*it == workshop)
            return true;
    }
    return false;
}

std::map<std::string, Tool *> Worker::getTools() const {
    return this->tools;
}

std::list<Workshop *> Worker::getWorkshops() const {
    return this->workshops;
}
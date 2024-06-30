#include "../includes/Worker.hpp"

Worker::Worker(float x, float y, int level, int exp) : coordonnee(Position(x, y)), stat(Statistic(level, exp)) {
}

Worker::~Worker() {
    // for (std::map<std::string, Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++) {
    //     it->second->setWorker(NULL);
    //     it->second->setEquiped();
    // }
    // this->tools.clear();
    
    // for (std::list<Workshop *>::iterator it = this->workshops.begin(); it != this->workshops.end(); it++) {
    //     (*it)->deleteWorker(this);
    // }
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

void   Worker::addWorkshop(Workshop *workshop) {
    if (workshop) {
        if (this->isWorkerHaveTool(workshop->getToolNeeded()) == false) {
            std::cout << "Worker doesn't have the required tool" << std::endl;
            return ;
        }

        if (workshop->isWorkerInWorkshop(this)) {
            std::cout << "Worker already in the workshop" << std::endl;
            return ;
        }
        this->workshops.push_back(workshop);
        workshop->addWorker(this);
        std::cout << "Workshop added" << std::endl;
    }
    else 
        std::cout << "Workshop is NULL" << std::endl;
}

void   Worker::deleteWorkshop(Workshop *workshop) {
    if (workshop) {
        if (!workshop->isWorkerInWorkshop(this)) {
            std::cout << "Worker not in the workshop" << std::endl;
            return ;
        }
        workshop->deleteWorker(this);
        this->workshops.remove(workshop);
        std::cout << "Workshop removed" << std::endl;
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
                    (*it)->deleteWorker(this);
                    it = workshops.erase(it);
                    std::cout << "Worker removed from the workshop" << std::endl;
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

std::map<std::string, Tool *> Worker::getTools() const {
    return this->tools;
}

std::list<Workshop *> Worker::getWorkshops() const {
    return this->workshops;
}
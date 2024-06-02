  #include "../includes/Worker.hpp"

Worker::Worker(float x, float y, int level, int exp) : coordonnee(Position(x, y)), stat(Statistic(level, exp)) {
    this->tool = NULL;
}

Worker::~Worker() {
    if (this->tool) {
        this->tool->setWorker(NULL);
        this->tool->setEquiped();
        this->tool = NULL;
    }
}

void    Worker::equipTool(Tool* tool) {
    if (tool) {
        if (tool->getWorker())
            if (tool->getWorker()->tool)
                tool->getWorker()->unequipTool();
        
        if (this->tool)
            this->unequipTool();

        this->tool = tool;
        this->tool->setWorker(this);
        this->tool->setEquiped();

        std::cout << "Worker is equiping a Tool" << std::endl;
    }
    else std::cout << "Error: Cannot equip NULL tool" << std::endl;
}

void    Worker::unequipTool() {
    if (this->tool) {

        std::list<Workshop *>::iterator it;

        for (it = this->workshops.begin(); it != this->workshops.end(); it++) {
            if ((*it)->getToolNeeded() == this->tool->getStr()) {
                (*it)->deleteWorker(this);
                break;
            }
        }

        this->tool->setEquiped();
        this->tool->setWorker(NULL);
        this->tool = NULL;

        std::cout << "Worker is unequiping a tool" << std::endl;
    }
    else
        std::cout << "Error: Cannot unequip empty hands" << std::endl;
}

void    Worker::useTool(){
    if (this->tool)
        this->tool->use();
    else
        std::cout << "Error: Cannot use inexistant tool" << std::endl;
}

void    Worker::addWorkshop(Workshop* workshop) {
    if (workshop) {
        if (!isInWorkshop(workshop)) {
            this->workshops.push_back(workshop);
            std::cout << "Worker has registered in Workshop" << std::endl;
        }
        else std::cout << "Error: Already registered in this workshop" << std::endl;
    }
    else std::cout << "Error: Cannot register in NULL workshop" << std::endl;

}

void    Worker::deleteWorkshop(Workshop *workshop) {
    if (workshop) {
        if (isInWorkshop(workshop)) {
            for (std::list<Workshop *>::iterator it = this->workshops.begin(); it != this->workshops.end(); ++it) {
                if (*it == workshop) {
                    this->workshops.erase(it);
                    std::cout << "Deleted a Workshop" << std::endl;
                    break;
                }
            }
        }
        else std::cout << "Error: Worker has not registered in this workshop" << std::endl;\
    }
    else std::cout << "Error: Cannot delete NULL workshop" << std::endl;
}

bool    Worker::isEquiped() const {
    if (this->tool)
        return true;
    return false;
}

bool    Worker::isInWorkshop(Workshop* workshop) {
    if (workshop) {
        for (std::list<Workshop *>::iterator it = this->workshops.begin(); it != this->workshops.end(); ++it) {
            if (*it == workshop)
                return true;
        }
    }
    else std::cout << "Error: Cannot check NULL workshop" << std::endl;

    return false;
}

void    Worker::work() {
    if (this->workshops.size() > 0)
        std::cout << "I am currently working" << std::endl;
    else std::cout << "I can't currently working" << std::endl;
}

const Tool* Worker::getEquipedTool() const {
    return this->tool;
}
  #include "../includes/Worker.hpp"

Worker::Worker(float x, float y, int level, int exp) : pos(x, y), stat(level, exp) {
    this->tool = NULL;
}

Worker::~Worker() {} 

void    Worker::equipTool(Tool* tool) {
    if (tool->getWorker())
        tool->getWorker()->desequipTool();

    this->tool = tool;
    this->tool->setWorker(this);
    this->tool->setEquiped();

    std::cout << "Equiping a Tool" << std::endl;
}

void    Worker::desequipTool() {
    if (this->tool) {
        this->tool->setEquiped();
        this->tool = NULL;

        std::cout << "Desequiping a tool" << std::endl;
    }
    else
        std::cout << "Empty hands for DESEQUIP" << std::endl;
}

void    Worker::useTool(){
    if (this->tool)
        this->tool->use();
    else
        std::cout << "Empty hands for USE" << std::endl;
}

void    Worker::addWorkshop(Workshop* workshop) {
    if (!isInWorkshop(workshop)) {
        if (workshop) {
            this->workshops.push_back(workshop);
            std::cout << "Registered in Workshop" << std::endl;
        }
    }
    else std::cout << "Already registered in this workshop" << std::endl;
}

void    Worker::deleteWorkshop(Workshop *workshop) {
    if (isInWorkshop(workshop)) {
        if (workshop) {
            for (std::list<Workshop *>::iterator it = this->workshops.begin(); it != this->workshops.end(); ++it) {
                if (*it == workshop) {
                    this->workshops.erase(it);
                    std::cout << "Deleted a Workshop" << std::endl;
                    break;
                }
            }
        }
    }
    else std::cout << "Not registered in this workshop" << std::endl;
}

bool    Worker::isInWorkshop(Workshop* workshop) {
    for (std::list<Workshop *>::iterator it = this->workshops.begin(); it != this->workshops.end(); ++it) {
        if (*it == workshop)
            return true;
    }
    return false;
}

void    Worker::work() {
    if (this->workshops.size() > 0)
        std::cout << "I am currently working" << std::endl;
    else std::cout << "I can't currently working" << std::endl;
}
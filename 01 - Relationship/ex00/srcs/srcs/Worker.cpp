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
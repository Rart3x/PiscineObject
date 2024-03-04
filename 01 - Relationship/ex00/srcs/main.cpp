#include "./includes/Hammer.hpp"
#include "./includes/Shovel.hpp"
#include "./includes/Tool.hpp"
#include "./includes/Worker.hpp"
#include "./includes/Workshop.hpp"

int main (void) {
    Tool    *tool;

    Shovel  *shovel = new Shovel();
    Hammer  *hammer = new Hammer();
    
    Worker  worker(5, 5, 100, 100000);
    Worker  worker1(5, 5, 100, 100000);

    Workshop *workshop = new Workshop();
    Workshop *workshop1 = new Workshop();

    tool = hammer;

    worker.equipTool(shovel);
    worker1.equipTool(shovel);

    std::cout << "<---------------------------------------->" << std::endl;

    worker.useTool();
    worker1.useTool();

    std::cout << "<---------------------------------------->" << std::endl;

    worker.desequipTool();
    worker1.desequipTool();

    std::cout << "<---------------------------------------->" << std::endl;

    shovel->use();
    tool->use();

    std::cout << "<---------------------------------------->" << std::endl;

    worker1.equipTool(tool);
    worker1.useTool();

    std::cout << "<---------------------------------------->" << std::endl;

    workshop->addWorker(&worker);
    workshop->addWorker(&worker);

    std::cout << "<---------------------------------------->" << std::endl;

    workshop1->addWorker(&worker);

    std::cout << "<---------------------------------------->" << std::endl;
    workshop->deleteWorker(&worker);
    workshop->deleteWorker(&worker);

    std::cout << "<---------------------------------------->" << std::endl;
    workshop1->deleteWorker(&worker);

    std::cout << "<---------------------------------------->" << std::endl;
    worker.work();
    workshop->addWorker(&worker);
    worker.work();

    std::cout << "<---------------------------------------->" << std::endl;
    workshop->addWorker(&worker1);
    workshop->executeWorkDay();

    delete shovel;
    delete workshop;
    delete workshop1;
}
#include "./includes/Hammer.hpp"
#include "./includes/Shovel.hpp"
#include "./includes/Tool.hpp"
#include "./includes/Worker.hpp"

int main (void) {
    Tool    *tool;
    
    Shovel  *shovel = new Shovel();
    Hammer  *hammer = new Hammer();
    
    Worker  worker(5, 5, 100, 100000);
    Worker  worker1(5, 5, 100, 100000);

    tool = hammer;

    worker.equipTool(shovel);
    worker1.equipTool(shovel);

    worker.useTool();
    worker1.useTool();

    worker.desequipTool();
    worker1.desequipTool();

    shovel->use();
    tool->use();

    worker1.equipTool(tool);
    worker1.useTool();

    delete shovel;
}
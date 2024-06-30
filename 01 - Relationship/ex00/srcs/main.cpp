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
    Worker  *worker2 = new Worker(5, 5, 100, 100000);
    Worker  *worker3 = new Worker(5, 5, 100, 100000);

    tool = hammer;

    {
        std::cout << std::endl;
        std::cout << "<-------------------Equiping/unequiping--------------------->" << std::endl;
        std::cout << std::endl;

        worker.equipTool(hammer);
        worker.equipTool(shovel);
        worker.equipTool(hammer);

        std::cout << std::endl;

        hammer->printEquiped();
        shovel->printEquiped();

        std::cout << std::endl;

        worker.AmIEquiped(hammer);
        worker.AmIEquiped(shovel);

        std::cout << std::endl;

        worker.unequipTool(hammer);
        worker.unequipTool(shovel);
        worker.unequipTool(hammer);
    
        std::cout << std::endl;

        hammer->printEquiped();
        shovel->printEquiped();
    
        std::cout << std::endl;

        worker.AmIEquiped(hammer);
        worker.AmIEquiped(shovel);

        std::cout << std::endl;

        worker.equipTool(tool);
        worker.unequipTool(tool);
    }

    {
        std::cout << std::endl;
        std::cout << "<-------------------Use Tools--------------------->" << std::endl;
        std::cout << std::endl;

        hammer->printNumberOfUses();
        hammer->use();
        hammer->use();
        hammer->use();
        hammer->printNumberOfUses();
        tool->printNumberOfUses();
        tool->use();
        tool->use();
        tool->printNumberOfUses(); 
        
        std::cout << std::endl;
        
        shovel->printNumberOfUses();
        shovel->use();
        shovel->use();
        shovel->printNumberOfUses();
    }

    {
        std::cout << std::endl;
        std::cout << "<-------------------NULL/Empty Checks--------------------->" << std::endl;
        std::cout << std::endl;

        worker.equipTool(NULL);
        worker.unequipTool(NULL);
    }

    {
        std::cout << std::endl;
        std::cout << "<-------------------Workshops--------------------->" << std::endl;
        std::cout << std::endl;

    }

    {
        std::cout << std::endl;
        std::cout << "<-------------------Deleting/Destructors--------------------->" << std::endl;
        std::cout << std::endl;

        worker2->equipTool(hammer);
        worker3->equipTool(shovel);

        std::cout << std::endl;

        hammer->printEquiped();
        shovel->printEquiped();

        delete worker2;
        delete worker3;

        std::cout << std::endl;

        hammer->printEquiped();
        shovel->printEquiped();

        delete hammer;
        delete shovel;
    }
}
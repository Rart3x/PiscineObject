#include "./includes/Hammer.hpp"
#include "./includes/Shovel.hpp"
#include "./includes/Tool.hpp"
#include "./includes/Worker.hpp"
#include "./includes/Workshop.hpp"

void printMap(std::map<std::string, Tool *> tools) {
    for (std::map<std::string, Tool *>::iterator it = tools.begin(); it != tools.end(); it++) {
        std::cout << it->first << std::endl;
    }
}


int main (void) {
    Tool    *tool;

    Shovel  *shovel = new Shovel();
    Hammer  *hammer = new Hammer();
    Hammer  *hammer1 = new Hammer();
    
    Worker  worker(5, 5, 100, 100000);
    Worker  worker1(5, 5, 100, 100000);
    Worker  *worker2 = new Worker(5, 5, 100, 100000);
    Worker  *worker3 = new Worker(5, 5, 100, 100000);

    Workshop workshop("Hammer");
    Workshop workshop1("Shovel");

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

        workshop.addWorker(NULL);
        workshop.deleteWorker(NULL);

        worker.addWorkshop(NULL);
        worker.deleteWorkshop(NULL);
    }

    {
        std::cout << std::endl;
        std::cout << "<-------------------Workshops--------------------->" << std::endl;
        std::cout << std::endl;

        workshop.addWorker(&worker);

        std::cout << std::endl;

        worker.equipTool(hammer);

        std::cout << std::endl;

        workshop.addWorker(&worker);
        workshop1.addWorker(&worker);
        
        std::cout << std::endl;

        worker.equipTool(shovel);
        
        std::cout << "TEST" << std::endl;

        workshop1.addWorker(&worker);
        workshop1.addWorker(&worker);

        std::cout << std::endl;

        worker.addWorkshop(&workshop);
        worker.addWorkshop(&workshop1);

        std::cout << std::endl;

        workshop.deleteWorker(&worker);
        workshop1.deleteWorker(&worker);

        std::cout << std::endl;

        worker.addWorkshop(&workshop);
        worker.addWorkshop(&workshop1);
        worker1.equipTool(hammer1);
        worker1.addWorkshop(&workshop);

        std::cout << std::endl;

        worker.work();

        std::cout << std::endl;

        workshop.executeWorkDay();

        std::cout << std::endl;

        worker.unequipTool(hammer);
        worker.unequipTool(shovel);

        std::cout << std::endl;

        worker.work();
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
        delete hammer1;
        delete shovel;
    }
}
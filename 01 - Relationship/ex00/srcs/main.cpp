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

    Workshop *workshop = new Workshop("Hammer");
    Workshop *workshop1 = new Workshop("Shovel");

    tool = hammer;

    {
        std::cout << std::endl;
        std::cout << "<-------------------Equiping/unequiping--------------------->" << std::endl;
        std::cout << std::endl;

        worker.equipTool(shovel);
        worker1.equipTool(hammer);

        std::cout << std::endl;

        shovel->printEquiped();
        hammer->printEquiped();

        std::cout << std::endl;

        worker.useTool();
        worker1.useTool();

        std::cout << std::endl;

        worker.equipTool(hammer);
        worker1.equipTool(shovel);
        
        std::cout << std::endl;

        shovel->printEquiped();
        hammer->printEquiped();

        std::cout << std::endl;

        worker.useTool();
        worker1.useTool();

        std::cout << std::endl;

        worker1.equipTool(tool);

        std::cout << std::endl;

        worker1.useTool();

        std::cout << std::endl;
        
        worker1.unequipTool();
    }

    {
        std::cout << std::endl;
        std::cout << "<-------------------NULL/Empty Checks--------------------->" << std::endl;
        std::cout << std::endl;

        worker.useTool();
        worker1.useTool();
        
        std::cout << std::endl;

        worker.equipTool(NULL);
        worker1.equipTool(NULL);

        std::cout << std::endl;

        workshop->addWorker(NULL);
        workshop1->addWorker(NULL);

        std::cout << std::endl;

        workshop->deleteWorker(NULL);
        workshop1->deleteWorker(NULL);

        std::cout << std::endl;

        workshop->isWorker(NULL);
        workshop1->isWorker(NULL);

        workshop->executeWorkDay();
    }

    {
        std::cout << std::endl;
        std::cout << "<-------------------Workshops--------------------->" << std::endl;
        std::cout << std::endl;

        workshop->addWorker(worker2);
        workshop->addWorker(worker3);

        std::cout << std::endl;

        worker2->equipTool(shovel);
        worker3->equipTool(hammer);

        std::cout << std::endl;

        workshop->addWorker(worker2);
        workshop->addWorker(worker3);

        std::cout << std::endl;

        workshop->isWorker(worker2);
        workshop->isWorker(worker3);

        std::cout << std::endl;

        workshop->deleteWorker(worker2);
        workshop->deleteWorker(worker2);

        std::cout << std::endl;

        worker2->work();
        worker3->work();

        std::cout << std::endl;

        workshop->isWorker(worker2);
        workshop->isWorker(worker3);

        std::cout << std::endl;

        workshop->addWorker(worker2);
        workshop->addWorker(worker2);
        workshop->addWorker(worker2);
        workshop->addWorker(worker2);

        std::cout << std::endl;

        workshop->executeWorkDay();

        std::cout << std::endl;

        workshop1->addWorker(worker2);
        workshop1->addWorker(worker3);

        std::cout << std::endl;

        worker2->work();
        worker3->work();

        std::cout << std::endl;

        worker2->unequipTool();

        shovel->printEquiped();

        // worker2->deleteWorkshop(workshop1);
        // worker3->deleteWorkshop(workshop1);
        // workshop->deleteWorker(worker2);
        // workshop->deleteWorker(worker3);
    }

    {
        std::cout << std::endl;
        std::cout << "<-------------------Deleting/Destructors--------------------->" << std::endl;
        std::cout << std::endl;

        worker2->equipTool(hammer);

        std::cout << std::endl;

        delete worker2;

        hammer->printEquiped();

        std::cout << std::endl;

        delete hammer;
        delete shovel;
        delete workshop;
        delete workshop1;
        delete worker3;
    }
}
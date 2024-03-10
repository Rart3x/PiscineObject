#include "./includes/Graph.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main(void) {

    {
        Graph graph;

        std::srand(static_cast<unsigned int>(std::time(NULL)));

        for (size_t i = 0; i < 10; ++i) {
            try {
                int x = std::rand() % 16;
                int y = std::rand() % 16;

                graph.addCoord(x, y);
            } 
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }
        graph.printCoord();
    }

    std::cout << std::endl;
    std::cout << std::endl;

    {
        Graph graph;

        try {
            graph.addCoord(0, 0);
            graph.addCoord(12, 12);
            graph.printCoord();

            graph.addCoord(-1, -1);
            graph.printCoord();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }        
    }
    return 0;
}

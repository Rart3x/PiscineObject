#include "./includes/Graph.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main(void) {
    
    Graph graph;

    {
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
    return 0;
}

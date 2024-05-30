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
        std::cout << std::endl;

        try {
            Vector2 vec1 = graph[2];
            std::cout << "Vec 1 :[" << vec1.x << ", " << vec1.y << "]" << std::endl;
            std::cout << std::endl;
            
            Vector2 vec2 = graph[9];
            std::cout << "Vec 2 :[" << vec2.x << ", " << vec2.y << "]" << std::endl;
            std::cout << std::endl;

            Vector2 vec3 = graph[10];
            std::cout << "Vec 3 :[" << vec3.x << ", " << vec3.y << "]" << std::endl;
            std::cout << std::endl;
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << std::endl;
    }

    {
        Graph graph;

        try {
            graph.addCoord(-1, -1);
            graph.printCoord();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }        
    }

    {
        Graph   graph;
        Vector2 vec(2, 3);

        graph.addVec(vec);
        graph.addCoord(2, 3);
        graph.printCoord();
    }
    return 0;
}

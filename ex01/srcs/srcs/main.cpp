#include "../includes/Graph.hpp"

int main (void) {

    Graph graph;

    graph.addCoord(0, 0);
    graph.addCoord(2, 2);
    graph.addCoord(4, 2);
    graph.addCoord(2, 4);
    graph.addCoord(10, 10);
        
    graph.printCoord();
}
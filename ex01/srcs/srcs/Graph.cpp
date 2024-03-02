#include "../includes/Graph.hpp"

Graph::Graph() : size(0) {}

Graph::~Graph() {}

void    Graph::addCoord(float x, float y) {
    if (x > this->maxX) maxX = x;
    if (y > this->maxY) maxY = y;

    this->coordinates.push_back(Coordinate(x, y));
    this->size++;
}

void Graph::printCoord() const {
    for (int i = maxY; i >= 0; --i) {
        std::cout<< i << " ";
        for (int j = 0; j <= maxX; ++j) {
            bool found = false;
            for (std::list<Coordinate>::const_iterator it = coordinates.begin(); it != coordinates.end(); ++it) {
                if (it->x == j && it->y == i) {
                    std::cout << "X ";
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << ". ";
        }
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (int j = 0; j <= maxX; ++j) {
        std::cout << j << " ";
    }
    std::cout << std::endl;
}

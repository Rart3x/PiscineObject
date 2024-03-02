#pragma once

#include <iostream>
#include <list>

struct Coordinate {
    float   x;
    float   y;

    Coordinate(float x_val, float y_val) : x(x_val), y(y_val) {}
};

class Graph {

    public:
        Graph();
        ~Graph();

        void    addCoord(float x, float y);
        void    printCoord(void) const;

    private:
        size_t  size;

        float   maxX;
        float   maxY;

        std::list<Coordinate>   coordinates;
};
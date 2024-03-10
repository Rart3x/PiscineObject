#pragma once

#include "Exceptions.hpp"

#include <iostream>
#include <list>

struct Vector2 {
    float   x;
    float   y;

    Vector2(float x_val, float y_val) : x(x_val), y(y_val) {}
};

class Graph {

    public:
        Graph();
        ~Graph();

        void    addCoord(float x, float y);
        void    addVec(Vector2& vec);
        void    printCoord(void) const;

    private:
        size_t  size;

        float   maxX;
        float   maxY;

        std::list<Vector2>   coordinates;
};
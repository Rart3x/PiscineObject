#pragma once

#include "shape.hpp"

#include <iostream>

class Triangle : public Shape
{
    public:
        Triangle(int side1, int side2, int side3) : Shape(), side1(side1), side2(side2), side3(side3)
        {
            if (side1 <= 0 || side2 <= 0 || side3 <= 0)
                throw std::invalid_argument("Sides must be greater than 0.");
        }
        ~Triangle() {}

        void perimeter()
        {
            std::cout << "Triangle perimeter: " << side1 + side2 + side3 << "cm" << std::endl;
        }

    private:
        int side1;
        int side2;
        int side3;
};
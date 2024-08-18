#pragma once

#include "shape.hpp"

#include <iostream>

class Circle : public Shape
{
    public:
        Circle(int radius) : Shape(), radius(radius)
        {
            if (radius <= 0)
                throw std::invalid_argument("Radius must be greater than 0.");
        }
        ~Circle() {}

        void perimeter()
        {
            std::cout << "Circle perimeter: " << 2 * 3.14159 * radius << "cm" << std::endl;
        }

    private:
        int radius;
};
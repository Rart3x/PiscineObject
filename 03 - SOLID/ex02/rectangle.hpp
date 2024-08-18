#pragma once

#include "shape.hpp"

#include <iostream>

class Rectangle : public Shape
{
    public:
        Rectangle(int width, int height) : Shape(), width(width), height(height)
        {
            if (width <= 0 || height <= 0)
                throw std::invalid_argument("Width and height must be greater than 0.");
        }
        ~Rectangle() {}

        void perimeter()
        {
            std::cout << "Rectangle perimeter: " << 2 * (width + height) << "cm" << std::endl;
        }

    private:
        int width;
        int height;
};
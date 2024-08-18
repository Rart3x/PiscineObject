#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "triangle.hpp"

int main()
{

    std::cout << "\033[1;34m" << "Circle ERROR" << "\033[0m" << std::endl;

    try
    {
        Circle circle(0);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "\033[1;34m" << "Rectangle ERROR" << "\033[0m" << std::endl;

    try
    {
        Rectangle rectangle(5, 0);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "\033[1;34m" << "Triangle ERROR" << "\033[0m" << std::endl;

    try
    {
        Triangle triangle(5, 10, 0);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "\033[1;34m" << "Perimeters" << "\033[0m" << std::endl;

    try
    {
        Circle circle(5);
        Rectangle rectangle(2, 3);
        Triangle triangle(5, 10, 15);

        circle.perimeter();
        rectangle.perimeter();
        triangle.perimeter();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}
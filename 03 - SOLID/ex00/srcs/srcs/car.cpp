#include "../includes/car.hpp"

Car::Car() : status(false), speed(0), wheels(0), gears(0) {}
Car::~Car() {}

void    Car::start() {
    this->status = true;
}

void    Car::stop() {
    this->status = false;
}

void    Car::accelerate(const float speed) {
    this->speed += speed;
}

void    Car::shift_gears_up() {
    if (this->gears < 5)
        this->gears++;
}

void    Car::shift_gears_down() {
    if (this->gears > 0)
        this->gears--;
}

void    Car::reverse() {
    this->gears = -1;
}
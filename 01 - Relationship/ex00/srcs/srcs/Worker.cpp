#include "../includes/Worker.hpp"

Worker::Worker(float x, float y, int level, int exp) : pos(x, y), stat(level, exp) {
    this->shovel = NULL;
}

Worker::~Worker() {} 

void    Worker::equipShovel() {
    this->shovel = new Shovel();
}
#pragma once

#include <iostream>

class Car
{
    public:
        Car();
        ~Car();

        void    start();
        void    stop();

        void    accelerate(int speed);
        void    decelerate(int speed);

        void    shift_gears_up();
        void    shift_gears_down();

        void    reverse();

        void    turn_wheel(int angle);
        void    straighten_wheels();

        void    apply_force_on_brakes(int force);
        void    apply_emergency_brakes();

    private:
        bool    status;

        double     brakes;
        double     speed;
        double     wheels;

        int     gears;
};

#pragma once

#include <iostream>

class Car {

    public:
        Car();
        ~Car();

        void    start();
        void    stop();

        void    accelerate(const float speed);

        void    shift_gears_up();
        void    shift_gears_down();
        void    reverse();

        void    turn_wheel(const float angle);
        void    straighten_wheels();

        void    apply_force_on_brakes(const float force);
        void    apply_emergency_brakes();
        

    private:
        bool    status;

        float   speed;
        float   wheels;
        
        int     gears;
};
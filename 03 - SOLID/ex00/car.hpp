#pragma once

#include <iostream>

class Car
{
    public:
        Car(): status(false), brakes(0), speed(0), wheels(0), gears(0) {}
        ~Car() {}

        void    start()
        {
            if (!this->status)
            {
                this->status = true;
                std::cout << "Car started" << std::endl;
            }
        }

        void    stop()
        {
            if (this->status)
            {
                this->status = false;

                this->brakes = 0;
                this->gears = 0;
                this->speed = 0;
                this->wheels = 0;

                std::cout << "Car stopped" << std::endl;
            }
        }

        void    accelerate(int speed)
        {
            if (this->status && speed > 0)
            {
                this->speed += speed;
                std::cout << "Car accelerated to " << this->speed << " km/h" << std::endl;
            }
        }

        void    shift_gears_up()
        {
            if (this->status && this->gears < 5)
            {
                this->gears++;
                std::cout << "Car shifted up to gear " << this->gears << std::endl;
            }
            else if (this->status && this->gears == 5)
                std::cout << "Car is already in top gear" << std::endl;
        }

        void    shift_gears_down()
        {
            if (this->status && this->gears > 0)
            {
                this->gears--;
                std::cout << "Car shifted down to gear " << this->gears << std::endl;
            }
            else if (this->status && this->gears == 0)
                std::cout << "Car is already in neutral" << std::endl;
        }

        void    reverse()
        {
            if (this->status)
            {
                this->gears = -1;
                std::cout << "Car is in reverse" << std::endl;
            }
        }

        void    turn_wheel(int angle)
        {
            if (this->status)
            {
                this->wheels += angle;

                if (this->wheels > 360)
                    this->wheels -= 360;
                std::cout << "Car turned wheels to " << angle << " degrees, angle is now " << this->wheels << " degrees" << std::endl;
            }
        }

        void    straighten_wheels()
        {
            if (this->status && this->wheels != 0)
            {
                this->wheels = 0;
                std::cout << "Car wheels are straight" << std::endl;
            }
        }

        void    apply_force_on_brakes(int force)
        {
            if (this->status && force > 0 && force < 100)
            {
                if (this->brakes + force > 100)
                    this->brakes = 100;
                else
                    this->brakes += force;

                this->decelerate(this->speed * (1 - (force / 100.0)));

                std::cout << "Car applied " << force << " N of force on brakes, speed is now " << this->speed << " km/h" << std::endl;
            }
        }

        void    apply_emergency_brakes()
        {
            if (this->status)
            {
                this->brakes = 100;
                this->decelerate(this->speed);

                std::cout << "Car applied emergency brakes, speed is now " << this->speed << " km/h" << std::endl;
            }
        }

        void    decelerate(int speed)
        {
            if (this->status && speed >= 0)
            {
                this->speed -= speed;

                if (this->speed < 0)
                    this->speed = 0;
            }
        }

    private:
        bool    status;

        double     brakes;
        double     speed;
        double     wheels;

        int     gears;
};

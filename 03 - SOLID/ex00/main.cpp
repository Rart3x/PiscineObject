#include "car.hpp"

int main (void)
{
    Car car;

    {
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "\033[34mStarting/Stopping the car\033[0m" << std::endl;
        std::cout << std::endl;

        car.start();
        car.start();
        car.stop();
        car.stop();

        std::cout << std::endl;
    }

    {
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "\033[34mAccelerating the car\033[0m" << std::endl;
        std::cout << std::endl;

        car.accelerate(50);
        car.start();
        car.accelerate(50);
        car.accelerate(-5050);

        std::cout << std::endl;

        car.stop();

        std::cout << std::endl;
    }

    {
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "\033[34mShifting gears\033[0m" << std::endl;
        std::cout << std::endl;

        car.shift_gears_up();
        car.shift_gears_down();

        car.start();
        car.reverse();

        std::cout << std::endl;

        for (int i = 0; i < 7; i++)
            car.shift_gears_up();

        std::cout << std::endl;

        for (int i = 0; i < 6; i++)
            car.shift_gears_down();

        std::cout << std::endl;

        car.stop();

        std::cout << std::endl;
    }

    {
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "\033[34mTurn wheels\033[0m" << std::endl;
        std::cout << std::endl;

        car.start();

        std::cout << std::endl;

        car.turn_wheel(90);
        car.turn_wheel(-90);
        car.turn_wheel(0);
        car.turn_wheel(359);

        car.straighten_wheels();

        std::cout << std::endl;

        car.stop();

        std::cout << std::endl;
    }

    {
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "\033[34mApply brakes\033[0m" << std::endl;
        std::cout << std::endl;

        car.start();

        std::cout << std::endl;

        car.accelerate(50);
        car.apply_force_on_brakes(50);
        car.accelerate(200);
        car.apply_emergency_brakes();

        std::cout << std::endl;

        car.stop();
    }
}
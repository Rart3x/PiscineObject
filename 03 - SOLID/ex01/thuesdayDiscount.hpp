#pragma once

#include <iostream>

class ThuesdayDiscountCommand : public Command
{
    public:
        ThuesdayDiscountCommand();
        ~ThuesdayDiscountCommand();

        void get_total_price()
        {
            double total_price = 0;

            for (auto &article : articles)
            {
                if (date.day_of_week == 2)
                    article.second *= 0.9;
                total_price += article.second;
            }
            std::cout << "Total price: " << total_price << std::endl;
        }
};
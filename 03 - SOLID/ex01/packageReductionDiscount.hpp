#pragma once

#include <iostream>

class PackageReductionDiscountCommand : public Command
{
    public:
        PackageReductionDiscountCommand();
        ~PackageReductionDiscountCommand();

        void get_total_price()
        {
            double total_price = 0;

            for (auto &article : articles)
            {
                total_price += article.second;
            }

            if (total_price > 150)
                total_price -= 10;

            std::cout << "Total price: " << total_price << std::endl;
        }
};
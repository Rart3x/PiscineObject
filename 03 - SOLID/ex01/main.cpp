#include "command.hpp"
#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"

int main()
{
    PackageReductionDiscountCommand     c1 = PackageReductionDiscountCommand();
    ThuesdayDiscountCommand             c2 = ThuesdayDiscountCommand();

    std::cout << "\033[34mDiscount Reduction for 154$ of articles\033[0m" << std::endl;

    c1.add_article("apple", 50);
    c1.add_article("banana", 50);
    c1.add_article("orange", 50);
    c1.add_article("apple", 4);
    c1.get_total_price();

}
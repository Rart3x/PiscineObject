#pragma once

#include <chrono>
#include <ctime>
#include <iostream>
#include <map>

class Command
{
    public:
        Command() {}
        virtual ~Command() = 0;

        virtual void get_total_price() = 0;

    protected:
        int                                     id;

        std::chrono::system_clock::time_point   date;
        std::map<std::string, int>              articles;
        std::string                             client;


        void         add_article(std::string article, int quantity)
        {
            if (quantity < 0)
            {
                std::cerr << "Quantity cannot be negative" << std::endl;
                return;
            }

            if (articles.find(article) != articles.end())
                articles[article] += quantity;
            else
                articles[article] = quantity;
        }
};
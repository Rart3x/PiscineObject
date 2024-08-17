#pragma once

#include <chrono>
#include <ctime>
#include <iostream>
#include <map>

class Command
{
    public:
        Command();
        virtual ~Command() = 0;

        virtual void get_total_price() = 0;

    private:
        int                                     id;

        std::chrono::system_clock::time_point   date;
        std::map<std::string, int>              articles;
        std::string                             client;
};
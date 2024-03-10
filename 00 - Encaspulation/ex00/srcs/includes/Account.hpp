#pragma once

#include <iostream>

class Account { 

    public:
        // Constructor/Destructor //
        ~Account();

        // Getters functions //
        double      getAmount(void) const;
        int         getId(void) const;

        // Setters functions //

        // Overloads functions //
        friend std::ostream& operator <<(std::ostream& p_os, const Account& p_account);

    private:
        friend class Bank;

        double  amount;

        int     id;

        Account(int id);
};
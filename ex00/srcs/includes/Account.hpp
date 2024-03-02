#pragma once

#include <iostream>

class Account { 

    public:
        // Constructor/Destructor //
        Account(int id);
        ~Account();

        // Getters functions //
        double    getAmount() const;
        int       getCurrentId() const;
        int       getId() const;
        
        // Setters functions //

        // Overloads functions //
        friend std::ostream& operator <<(std::ostream& p_os, const Account& p_account);

    private:
        friend class Bank;

        double  amount;

        int     currentId;
        int     id;

        void    creditAmount(const double amount);
        void    debitAmount(const double amount);
};
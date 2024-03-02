#pragma once

#include <vector>

#include "Account.hpp"

class Bank { 

    public:
        // Constructor/Destructor //
        Bank();
        ~Bank();

        void    addAccount(Account* account);
        void    creditAccount(const double amount, Account &account);
        void    debitAccount(const double amount, Account &account);

        void    creditLiquidity(const double &amount);
        
        // Getters functions //
        std::vector<Account *>  getClientAccounts() const;
        int                     getLiquidity() const;
        
        // Setters functions //
        void    setLiquidity(const int liquidity);

    private:
        int liquidity;

        std::vector<Account *> clientAccounts;
};

// Overloads functions //
std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
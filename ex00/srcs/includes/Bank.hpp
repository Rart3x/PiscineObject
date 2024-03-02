#pragma once

#include <map>

#include "Account.hpp"

class Bank { 

    public:
        // Constructor/Destructor //
        Bank();
        ~Bank();

        void        addAccount(Account* account);
        Account     createAccount();
        void        creditAccount(const double amount, Account &account);
        void        debitAccount(const double amount, Account &account);
        void        deleteAccount(const int accountId);

        void        creditLiquidity(const double amount);

        void        loan(const double amount, const int accountId);
        
        // Getters functions //
        std::map<const int, Account *>  getClientAccounts() const;
        double                          getLiquidity() const;
        
        // Setters functions //
        void    setLiquidity(const int liquidity);

        Account* operator [] (const int accountId);

    private:
        int currentAccountId;
        double liquidity;

        std::map<const int, Account*> clientAccounts;
};

// Overloads functions //
std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
#pragma once

#include "Account.hpp"
#include "Exceptions.hpp"

#include <map>

class Bank { 

    public:
        // Constructor/Destructor //
        Bank();
        ~Bank();

        // Functions //
        void                                    addAccount(Account* account);
        void                                    createAccount();
        void                                    creditAccount(const double amount, Account &account);
        void                                    debitAccount(const double amount, Account &account);
        void                                    deleteAccount(const int accountId);

        void                                    creditLiquidity(const double amount);
        void                                    debitLiquidity(const double amount);

        bool                                    isClient(const int accountId) const;

        void                                    loan(const double amount, const int accountId);
        void                                    loanAccount(const double amount, Account &account);

        // Getters functions //
        const Account&                          getAccount(const int accountId);
        std::map<const int, Account*>           getClientAccounts() const;
        double                                  getLiquidity() const;
        
        // Setters functions //
        void                                    setLiquidity(double liquidity);

        // Overloads functions //
        const Account& operator [] (const int accountId);

    private:
        int     currentAccountId;
        double  liquidity;

        std::map<const int, Account*> clientAccounts;
};

// Overloads functions //
std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
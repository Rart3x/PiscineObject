#include "../includes/Bank.hpp"

Bank::Bank() : liquidity(0) {}
Bank::~Bank() {}

void    Bank::addAccount(Account* account) {
    this->clientAccounts.push_back(account);
}

void    Bank::creditAccount(const double amount, Account &account) {
    account.creditAmount(amount);
}

void    Bank::debitAccount(const double amount, Account &account) {
    account.debitAmount(amount);

}

std::vector<Account *>  Bank::getClientAccounts() const {
    return this->clientAccounts;
}

int   Bank::getLiquidity() const {
    return this->liquidity;
}

void    Bank::setLiquidity(const int liquidity) {
    this->liquidity = liquidity;
}

std::ostream&   operator <<(std::ostream& p_os, const Bank& p_bank) {
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.getLiquidity() <<std::endl;

    std::vector<Account *> clientsAccounts = p_bank.getClientAccounts();
    std::vector<Account *>::iterator it;

    for (it = clientsAccounts.begin(); it < clientsAccounts.end(); it++)
        p_os << *(*it) << std::endl;
    
    return (p_os);
}
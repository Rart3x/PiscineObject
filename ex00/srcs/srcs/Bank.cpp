#include "../includes/Bank.hpp"

Bank::Bank() : currentAccountId(0), liquidity(0) {}
Bank::~Bank() {}

void    Bank::addAccount(Account* account) {
    this->clientAccounts[account->getId()] = account;
}

Account    Bank::createAccount() {
    this->currentAccountId++;
    return Account(this->currentAccountId - 1);
}

void    Bank::creditAccount(const double amount, Account &account) {
    this->creditLiquidity(amount * 0.05);
    account.creditAmount(amount - (amount * 0.05));
}

void    Bank::creditLiquidity(const double amount) {
    this->liquidity += amount;
}

void    Bank::debitAccount(const double amount, Account &account) {
    account.debitAmount(amount);
}

void    Bank::deleteAccount(const int accountId) {
    this->clientAccounts.erase(accountId);
}

void    Bank::loan(const double amount, const int accountId) {
    if (this->liquidity >= amount && amount > 0
        && this->clientAccounts.find(accountId) != this->clientAccounts.end())
        this->creditAccount(amount, *this->clientAccounts[accountId]);
}

std::map<const int, Account *>  Bank::getClientAccounts() const {
    return this->clientAccounts;
}

double   Bank::getLiquidity() const {
    return this->liquidity;
}

void    Bank::setLiquidity(const int liquidity) {
    this->liquidity = liquidity;
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank) {
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;

    std::map<const int, Account *> clientsAccounts = p_bank.getClientAccounts();
    std::map<const int, Account *>::iterator it;

    for (it = clientsAccounts.begin(); it != clientsAccounts.end(); ++it)
        p_os << *(it->second) << std::endl;

    return p_os;
}
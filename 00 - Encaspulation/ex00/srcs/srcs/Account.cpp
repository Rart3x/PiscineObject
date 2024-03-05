#include "../includes/Account.hpp"

Account::Account(int id) : amount(0.0), id(id) {}
Account::~Account() {}

void    Account::creditAmount(const double amount) {
    this->amount += amount;
}

void    Account::debitAmount(const double amount) {
    this->amount -= amount;
}

double Account::getAmount() const {
    return this->amount;
}

int Account::getId() const {
    return this->id;
}

std::ostream& operator <<(std::ostream& p_os, const Account& p_account) {
    p_os << "[" << p_account.id << "] - [" << p_account.amount << "]";

    return (p_os);
}
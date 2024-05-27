#include "../includes/Bank.hpp"

//-----------------------------------Constructor/Destructor-----------------------------------//
Bank::Bank() : currentAccountId(0), liquidity(0) {}

Bank::~Bank() {
    std::map<const int, Account *>::iterator it;

    for (it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++) {
        if (isClient(it->first)) {
            delete(this->clientAccounts[it->first]);
        }
    }
}

//-----------------------------------Account functions-----------------------------------//
long    Bank::createAccount() {
    this->currentAccountId++;
    
    Account *newAccount = new Account(this->currentAccountId - 1);
    this->clientAccounts[newAccount->getId()] = newAccount;
    std::cout << "Bank just created account " << this->currentAccountId - 1 << std::endl;

    return (long)this->currentAccountId - 1;
}

void    Bank::creditAccount(const double amount, Account &account) {
    if (amount > 0) {
        this->creditLiquidity(amount * 0.05);
        account.amount += amount - (amount * 0.05);
        std::cout << "Bank just credited " << amount - (amount * 0.05) << " to account " << account.getId() << std::endl;
    } else
        throw Exceptions::CreditNotPossible();
}

void    Bank::debitAccount(const double amount, Account &account) {
    if (amount > 0) {
        account.amount -= amount;
        std::cout << "Bank just debited " << amount << " to account " << account.getId() << std::endl;
    }
    else
        throw Exceptions::DebitNotPossible();
}

void    Bank::deleteAccount(const int accountId) {
    if (isClient(accountId)) {
        std::cout << "Bank just deleted account " << this->clientAccounts[accountId]->getId() << std::endl;
        delete(this->clientAccounts[accountId]);
        this->clientAccounts.erase(accountId);
    }
    else
        throw Exceptions::InexistantAccount();
}

//-----------------------------------Liquidity functions-----------------------------------//
void    Bank::creditLiquidity(const double amount) {
    if (amount > 0) {
        this->liquidity += amount;
        std::cout << "Bank just credited " << amount << " to liquidity" << std::endl;
    }
    else
        throw Exceptions::CreditNotPossible();
}

void    Bank::debitLiquidity(const double amount) {
    if (amount > 0) {
        this->liquidity -= amount;
        std::cout << "Bank just debited " << amount << " to liquidity" << std::endl;
    }
    else
        throw Exceptions::DebitNotPossible();
}

//-----------------------------------Loan functions-----------------------------------//
void    Bank::loan(const double amount, const int accountId) {
    if (this->liquidity >= amount && amount > 0 && isClient(accountId)) {
        this->loanAccount(amount- (amount * 0.05), *this->clientAccounts[accountId]);
        this->debitLiquidity(amount - (amount * 0.05));
        std::cout << "Bank just loaned " << amount - (amount * 0.05) << " to account " << accountId << std::endl;
    } else
        throw Exceptions::LoanRequestRefused();
}

void    Bank::loanAccount(const double amount, Account &account) {
    account.amount += amount;
}

//-----------------------------------Utils functions-----------------------------------//
bool    Bank::isClient(const int accountId) const{
    if (this->clientAccounts.find(accountId) != this->clientAccounts.end())
        return true;
    return false;
}

//-----------------------------------Getters-----------------------------------//
std::map<const int, Account*>   Bank::getClientAccounts() const {
    return this->clientAccounts;
}

const Account& Bank::getAccount(const int accountId) {
    if (isClient(accountId))
        return *this->clientAccounts[accountId];
    throw Exceptions::InexistantAccount();
}

double Bank::getLiquidity() const {
    return this->liquidity;
}

//-----------------------------------Setters-----------------------------------//
void    Bank::setLiquidity(double liquidity) {
    this->liquidity = liquidity;
}

//-----------------------------------Overload operators-----------------------------------//
std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank) {
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;

    std::map<const int, Account *> clientsAccounts = p_bank.getClientAccounts();
    std::map<const int, Account *>::iterator it;

    for (it = clientsAccounts.begin(); it != clientsAccounts.end(); ++it)
        p_os << *(it->second) << std::endl;

    return p_os;
}

const Account&    Bank::operator[](const int accountId) {
    if (isClient(accountId))
        return *this->clientAccounts[accountId];
    throw Exceptions::InexistantAccount();
}
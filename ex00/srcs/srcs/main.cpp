#include "../includes/Account.hpp"
#include "../includes/Bank.hpp"

int main (void) {
	Account accountA = Account(1);
	Account accountB = Account(2);

	Bank bank = Bank();

	bank.setLiquidity(999);

	bank.addAccount(&accountA);
	bank.addAccount(&accountB);

	bank.creditAccount(200, accountA);
	bank.debitAccount(25, accountA);

	bank.creditAccount(200, accountB);
	bank.creditAccount(25, accountB);

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank;

	return (0);
}
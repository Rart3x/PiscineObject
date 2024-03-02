#include "../includes/Account.hpp"
#include "../includes/Bank.hpp"

int main (void) {

	Bank bank = Bank();

	Account accountA = bank.createAccount();
	Account accountB = bank.createAccount();

	bank.setLiquidity(1000);

	bank.addAccount(&accountA);
	bank.addAccount(&accountB);

	bank.creditAccount(100, accountA);
	bank.creditAccount(100, accountB);

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank;

	return (0);
}
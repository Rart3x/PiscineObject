#include "../includes/Account.hpp"
#include "../includes/Bank.hpp"

int main (void) {

	Bank bank = Bank();

	Account accountA = bank.createAccount();

	bank.setLiquidity(1000);

	bank.addAccount(&accountA);

	bank.creditAccount(100, accountA);
	bank.debitAccount(125, accountA);

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank;

	std::cout << " ----- " << std::endl;
	std::cout << " ----- " << std::endl;

	bank.loan(7, accountA.getId());

	std::cout << "Account : " << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank;

	Account *accountCopy = bank[0];

	std::cout << "COPY" << std::endl;
	std::cout << *accountCopy << std::endl;

	return (0);
}
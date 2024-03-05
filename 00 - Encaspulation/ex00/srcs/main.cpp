#include "./includes/Account.hpp"
#include "./includes/Bank.hpp"

int main (void) {

	Bank bank = Bank();

	Account accountA = bank.createAccount();

	bank.setLiquidity(1000);

	bank.addAccount(&accountA);

	bank.creditAccount(100, accountA);
	bank.debitAccount(125, accountA);

	std::cout << " ----- " << std::endl;

	try {
		std::cout << "Bank : " << std::endl;
		std::cout << bank;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << " ----- " << std::endl;

	try {
		bank.loan(500, accountA.getId());
		std::cout << "Bank after Loan: " << std::endl;
		std::cout << bank;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Account *accountCopy;

	try {
		accountCopy = bank[5];
		std::cout << "COPY" << std::endl;
		std::cout << *accountCopy << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
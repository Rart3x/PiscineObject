 #include "./includes/Account.hpp"
#include "./includes/Bank.hpp"

int main (void) {

	Bank bank = Bank();

	bank.setLiquidity(1000);

	bank.createAccount();
	Account accountA = bank.getAccount(0);

	// accountA.amount = 5; Modify Account object is FORBIDDEN outside from Bank object

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
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << " ----- " << std::endl;

	try {
		Account accountCopy = bank[0];
		std::cout << "COPY1" << std::endl;
		std::cout << accountCopy << std::endl;

		Account accountCopy1 = bank[5];
		std::cout << "COPY2" << std::endl;
		std::cout << accountCopy << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
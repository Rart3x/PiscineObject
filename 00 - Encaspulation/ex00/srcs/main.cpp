 #include "./includes/Account.hpp"
#include "./includes/Bank.hpp"

int main (void) {

	Bank bank = Bank();

	bank.setLiquidity(1000);

	bank.createAccount();
	bank.createAccount();
	bank.createAccount();
	long returnValue = bank.createAccount();

	std::cout << std::endl;
	std::cout << "Last account created ID: " << returnValue << std::endl;

	std::cout << std::endl;
	std::cout << bank << std::endl;
	std::cout << std::endl;
	
	try {
		bank.deleteAccount(3);
		bank.deleteAccount(2);
		bank.deleteAccount(1);
		bank.deleteAccount(7);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << bank << std::endl;

	bank.createAccount();

	std::cout << std::endl;
	std::cout << bank << std::endl;

	try {
		Account accountFalse = bank.getAccount(6);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// accountA.amount = 5; Modify Account object is FORBIDDEN outside from Bank object
	
	Account accountA = bank.getAccount(0);

	std::cout << "Bank ZOB: " << std::endl;
	std::cout << bank << std::endl;

	bank.creditAccount(100, accountA);
	bank.debitAccount(125, accountA);

	std::cout << std::endl;
	std::cout << " ----- " << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "Bank : " << std::endl;
		std::cout << bank;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << " ----- " << std::endl;
	std::cout << std::endl;

	try {
		bank.loan(500, accountA.getId());
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		bank.loan(100000, accountA.getId());
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << " ----- " << std::endl;
	std::cout << std::endl;

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

	bank.createAccount();
	bank.createAccount();
	bank.createAccount();
	bank.createAccount();
	bank.createAccount();

	return (0);
}
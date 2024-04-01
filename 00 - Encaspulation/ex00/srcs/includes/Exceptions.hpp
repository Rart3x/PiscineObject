#pragma once

#include <iostream>

class Exceptions{

	public :

		class	CreditNotPossible : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Error: Credit not possible");};
		};

		class	DebitNotPossible : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Error: Debit not possible");};
		};

		class	InexistantAccount : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Error: This account doesn't exist");};
		};

		class	LoanRequestRefused : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Your loan request has been refused.");};
		};
};
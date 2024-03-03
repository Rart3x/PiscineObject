#pragma once

#include <string>

class Exceptions{

	public :

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
#pragma once

#include <iostream>

class Exceptions{

	public :

		class	NegativeCoordinates : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Error: Can't add negative coordinates");};
		};

		class	InexistantVec : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Error: This Vec doesn't exist");};
		};


};
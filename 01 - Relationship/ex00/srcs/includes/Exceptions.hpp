#pragma once

#include <iostream>

class Exceptions{

	public :

		class	IDKException : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Error:");};
		};
};
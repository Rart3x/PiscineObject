#pragma once

#include <string>

class Exceptions{

	public :

		class	NegativeCoordinates : public std::exception
		{
			public:
				virtual const char *	what() const throw() {return ("Error: ZOB add negative coordinates");};
		};
};
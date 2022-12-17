#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

class Base
{

	public:

		virtual ~Base()
		{
			std::cout << "Base destructor called." << std::endl;
		}

};

#endif /* ************************************************************ BASE_H */
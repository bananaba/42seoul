#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>

class Base
{

	public:

		Base();
		Base( Base const & src );
		~Base();

		Base &		operator=( Base const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Base const & i );

#endif /* ************************************************************ BASE_H */
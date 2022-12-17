#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <cfloat>

class Scalar
{

	public:

		Scalar();
		~Scalar();
		static void	convert(const std::string& input);

	private:
		
		Scalar( Scalar const & src );	
		Scalar &		operator=( Scalar const & rhs );

};

std::ostream &			operator<<( std::ostream & o, Scalar const & i );

#endif /* ********************************************************** SCALAR_H */
#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>

class Scalar
{

	public:

		Scalar();
		Scalar( Scalar const & src );
		~Scalar();

		Scalar &		operator=( Scalar const & rhs );

		static void	convert(const std::string& literal);

	private:

};

std::ostream &			operator<<( std::ostream & o, Scalar const & i );

#endif /* ********************************************************** SCALAR_H */
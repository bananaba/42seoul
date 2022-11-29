#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>

class Point
{

	public:

		Point();
		Point( Point const & src );
		~Point();

		Point &		operator=( Point const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Point const & i );

#endif /* *********************************************************** POINT_H */
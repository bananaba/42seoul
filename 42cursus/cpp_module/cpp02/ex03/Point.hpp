#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{

	public:

		Point( void );
		Point( float const num1, float const num2 );
		Point( Point const & src );
		~Point( void );

		Point &		operator=( Point const & rhs );
		Point		operator+( Point const & point ) const;
		Point		operator-( Point const & point ) const;
		bool		operator==( Point const &point ) const;

		Fixed getX( void ) const;
		Fixed getY( void ) const;

	private:
	
		Fixed const	x;
		Fixed const	y;

};

std::ostream &			operator<<( std::ostream & o, Point const & i );

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* *********************************************************** POINT_H */
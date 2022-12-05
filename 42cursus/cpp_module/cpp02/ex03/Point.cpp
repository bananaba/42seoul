#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : x(0), y(0)
{
	//	std::cout << "Default constructor called" << std::endl;
}

Point::Point( float const num1, float const num2 ) : x(num1), y(num2)
{
//	std::cout << "Float constructor called" << std::endl;
}

Point::Point( Point const & src ) : x(src.getX()), y(src.getY())
{
//	std::cout << "Copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
//	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		const_cast<Fixed &>(this->x) = rhs.getX();
		const_cast<Fixed &>(this->y) = rhs.getY();
	}
	return (*this);
}

Point	Point::operator+( Point const &point ) const
{
	return (Point((this->getX() + point.getX()).toFloat(), (this->getY() + point.getY()).toFloat()));
}

Point	Point::operator-( Point const &point ) const
{
	return (Point((this->getX() - point.getX()).toFloat(), (this->getY() - point.getY()).toFloat()));
}

bool	Point::operator==( Point const &point ) const
{
	if (this->getX() == point.getX() && this->getY() == point.getY())
		return (true);
	return (false);
}

std::ostream &			operator<<( std::ostream & o, Point const & i )
{
	o << "X = " << i.getX() << " Y = " << i.getY();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Fixed	Point::getX( void ) const
{
	return (this->x);
}

Fixed	Point::getY( void ) const
{
	return (this->y);
}


/* ************************************************************************** */
#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed( const int num )
{
	std::cout << "Int constructor called" << std::endl;
	value = num << fractionalBits;
}

Fixed::Fixed( const float num )
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(num * (1 << fractionalBits));
}

Fixed &Fixed::operator=( const Fixed &fixed )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		value = fixed.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits( int const raw )
{
	value = raw;
}


float	Fixed::toFloat( void ) const;
int		Fixed::toInt( void ) const;

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed( int const num )
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = num << this->_fractionalBits;
}

Fixed::Fixed( float const num )
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(num * (1 << this->_fractionalBits));
}

Fixed &Fixed::operator=( Fixed const &fixed )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator>( Fixed const &fixed ) const
{
	if (this->getRawBits() > fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<( Fixed const &fixed ) const
{
	if (this->getRawBits() < fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=( Fixed const &fixed ) const
{
	if (this->getRawBits() >= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=( Fixed const &fixed ) const
{
	if (this->getRawBits() <= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==( Fixed const &fixed ) const
{
	if (this->getRawBits() == fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=( Fixed const &fixed ) const
{
	if (this->getRawBits() != fixed.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+( Fixed const &fixed )
{
	return (Fixed ((this->getRawBits() + fixed.getRawBits()) >> this->_fractionalBits));
}

Fixed	Fixed::operator-( Fixed const &fixed )
{
	return (Fixed ((this->getRawBits() - fixed.getRawBits()) >> this->_fractionalBits));
}

Fixed	Fixed::operator*( Fixed const &fixed )
{
	return (Fixed (this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/( Fixed const &fixed )
{
	return (Fixed ((float)this->getRawBits() / fixed.getRawBits()));
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp (*this);
	this->_value++;
	return (temp);
}

Fixed	&Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp (*this);
	this->_value--;
	return (temp);
}

Fixed	&Fixed::operator--()
{
	this->_value--;
	return (*this);
}


int		Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}


float	Fixed::toFloat( void ) const
{
	return ((float)this->_value / (1 << this->_fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (roundf(this->_value >> this->_fractionalBits));
}

Fixed		&Fixed::max( Fixed &a, Fixed &b )
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::max( Fixed const &a, Fixed const &b )
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed		&Fixed::min( Fixed &a, Fixed &b )
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::min( Fixed const &a, Fixed const &b )
{
	if (a < b)
		return (a);
	else
		return (b);
}


std::ostream &operator<<( std::ostream &out, Fixed const &fixed )
{
	out << fixed.toFloat();
	return (out);
}

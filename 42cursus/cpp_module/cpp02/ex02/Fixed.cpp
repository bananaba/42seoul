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

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed( const int num )
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = num << this->_fractionalBits;
}

Fixed::Fixed( const float num )
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(num * (1 << this->_fractionalBits));
}

Fixed &Fixed::operator=( const Fixed &fixed )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator>( const Fixed &fixed ) const
{
	if (this->toFloat() > fixed.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<( const Fixed &fixed ) const
{
	if (this->toFloat() < fixed.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>=( const Fixed &fixed ) const
{
	if (this->toFloat() >= fixed.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<=( const Fixed &fixed ) const
{
	if (this->toFloat() <= fixed.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator==( const Fixed &fixed ) const
{
	if (this->toFloat() == fixed.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator!=( const Fixed &fixed ) const
{
	if (this->toFloat() != fixed.toFloat())
		return (true);
	return (false);
}

Fixed	Fixed::operator+( const Fixed &fixed )
{
	return (Fixed (this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-( const Fixed &fixed )
{
	return (Fixed (this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*( const Fixed &fixed )
{
	return (Fixed (this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/( const Fixed &fixed )
{
	return (Fixed (this->toFloat() / fixed.toFloat()));
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
	return (this->_value >> this->_fractionalBits);
}

Fixed		&Fixed::max( Fixed &a, Fixed &b )
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::max( Fixed const &a, Fixed const &b )
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

Fixed		&Fixed::min( Fixed &a, Fixed &b )
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::min( Fixed const &a, Fixed const &b )
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}


std::ostream &operator<<( std::ostream &out, const Fixed &fixed )
{
	out << fixed.toFloat();
	return (out);
}

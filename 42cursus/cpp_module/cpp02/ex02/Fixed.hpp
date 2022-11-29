/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:21:56 by balee             #+#    #+#             */
/*   Updated: 2022/11/29 21:11:34 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		const static int	_fractionalBits = 8;
	public:
		Fixed( void );
		~Fixed( void );
		Fixed( const Fixed &fixed );
		Fixed( const int num );
		Fixed( const float num );
		Fixed	&operator=( const Fixed &fixed );
		bool	operator>( const Fixed &fixed ) const;
		bool	operator<( const Fixed &fixed ) const;
		bool	operator>=( const Fixed &fixed ) const;
		bool	operator<=( const Fixed &fixed ) const;
		bool	operator==( const Fixed &fixed ) const;
		bool	operator!=( const Fixed &fixed ) const;
		Fixed	operator+( const Fixed &fixed );
		Fixed	operator-( const Fixed &fixed );
		Fixed	operator*( const Fixed &fixed );
		Fixed	operator/( const Fixed &fixed );
		Fixed	operator++(int);
		Fixed	&operator++();
		Fixed	operator--(int);
		Fixed	&operator--();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<( std::ostream &out, const Fixed &fixed );

#endif

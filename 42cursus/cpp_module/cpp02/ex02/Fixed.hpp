/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:21:56 by balee             #+#    #+#             */
/*   Updated: 2022/11/30 17:38:05 by balee            ###   ########.fr       */
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
		Fixed( Fixed const &fixed );
		Fixed( int const num );
		Fixed( float const num );
		Fixed	&operator=( Fixed const &fixed );
		bool	operator>( Fixed const &fixed ) const;
		bool	operator<( Fixed const &fixed ) const;
		bool	operator>=( Fixed const &fixed ) const;
		bool	operator<=( Fixed const &fixed ) const;
		bool	operator==( Fixed const &fixed ) const;
		bool	operator!=( Fixed const &fixed ) const;
		Fixed	operator+( Fixed const &fixed );
		Fixed	operator-( Fixed const &fixed );
		Fixed	operator*( Fixed const &fixed );
		Fixed	operator/( Fixed const &fixed );
		Fixed	operator++(int);
		Fixed	&operator++();
		Fixed	operator--(int);
		Fixed	&operator--();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed		&max( Fixed &a, Fixed &b );
		static Fixed const	&max( Fixed const &a, Fixed const &b );
		static Fixed		&min( Fixed &a, Fixed &b );
		static Fixed const	&min( Fixed const &a, Fixed const &b );
};

std::ostream &operator<<( std::ostream &out, Fixed const &fixed );

#endif

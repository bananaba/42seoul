/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:21:56 by balee             #+#    #+#             */
/*   Updated: 2022/11/29 18:37:15 by balee            ###   ########.fr       */
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
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<( std::ostream &out, const Fixed &fixed );

#endif

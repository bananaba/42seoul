/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:21:56 by balee             #+#    #+#             */
/*   Updated: 2022/11/29 18:37:21 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		const static int	_fractionalBits = 8;
	public:
		Fixed( void );
		~Fixed( void );
		Fixed( const Fixed &fixed );
		Fixed	&operator = ( const Fixed &fixed );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif

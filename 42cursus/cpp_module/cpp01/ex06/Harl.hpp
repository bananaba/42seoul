/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:22:22 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:22:23 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	private:
		void		etc( void );
		void		debug( void );
		void		info( void );
		void		warning( void );
		void		error( void );
		void		(Harl::*f[5])( void );
		std::string	lv[4];
	public:
		void		complain( std::string level );
		void		harlFilter( std::string level );
		Harl( void );
		~Harl( void );
};

#endif

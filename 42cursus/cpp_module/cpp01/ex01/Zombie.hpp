/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:16:15 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:16:17 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	_name;
	public:
		void	announce( void );
		void	setName( std::string name );
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
};

Zombie*	zombieHorde( int N, std::string name );

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:16:00 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:16:01 by balee            ###   ########.fr       */
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
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif

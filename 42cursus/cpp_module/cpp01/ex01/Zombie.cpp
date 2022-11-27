/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:16:11 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:16:12 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	_name = name;
}

Zombie::~Zombie( void )
{
	std::cout << _name << ": killed" << std::endl;
}

Zombie::Zombie( void )
{
	_name = "";
}

Zombie::Zombie( std::string name )
{
	_name = name;
}

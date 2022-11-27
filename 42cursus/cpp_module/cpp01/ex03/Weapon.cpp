/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:17:13 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:18:02 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	&Weapon::getType( void )
{
	std::string	&typeREF = type;
	return (typeREF);
}

void	Weapon::setType( std::string _type )
{
	type = _type;
}

Weapon::Weapon( void )
{
	type = "";
}

Weapon::Weapon( std::string _type )
{
	type = _type;
}

Weapon::~Weapon( void )
{}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:16:38 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:20:24 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack(	void )
{
	std::cout << name << " attacks with their " << aWeapon.getType() << std::endl;
}

HumanA::HumanA( std::string _name, Weapon &_weapon ) : aWeapon(_weapon)
{
	name = _name;
}

HumanA::~HumanA( void )
{}

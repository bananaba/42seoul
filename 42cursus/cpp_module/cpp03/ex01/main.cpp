/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:44:15 by balee             #+#    #+#             */
/*   Updated: 2022/12/08 16:44:18 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	{
		ClapTrap a;
		ClapTrap b("CL4P-TP");
		a.attack("some one robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some another robot");
		b.takeDamage(5);
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("some the other robot");
		b.beRepaired(3);
		b.beRepaired(3);
	}
	{
		ScavTrap c;
		ScavTrap d("SC4V-TP");
		c.attack("some one robot");
		c.takeDamage(50);
		c.guardGate();
		c.takeDamage(60);
		c.beRepaired(50);
		c.guardGate();
		c.attack("some another robot");
		d.takeDamage(5);
		d.beRepaired(3);
		// for (int i = 0; i < 50; i++)
		// 	d.attack("some the other robot");
		d.beRepaired(3);
		d.beRepaired(3);
	}
	return (0);
}

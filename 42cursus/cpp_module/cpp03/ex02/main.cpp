/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:44:49 by balee             #+#    #+#             */
/*   Updated: 2022/12/08 16:46:31 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
		FragTrap a;
		FragTrap b("FR4G-TP");

		a.highFivesGuys();
		a.attack("some one robot");
		// a.guardGate();
		a.takeDamage(101);
		a.takeDamage(1);
		a.attack("some another robot");
		b.highFivesGuys();
		// for(int i = 0; i < 101; i++)
		// 	b.attack("some the other robot");
	}
	return (0);
}

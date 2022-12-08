/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:43:27 by balee             #+#    #+#             */
/*   Updated: 2022/12/08 16:43:30 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a;
	ClapTrap b("CL4P-TP");
	ClapTrap c(b);
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
	return (0);
}

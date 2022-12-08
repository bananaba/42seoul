/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:47:52 by balee             #+#    #+#             */
/*   Updated: 2022/12/08 16:47:53 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a;
	DiamondTrap b("DI4D_TP");
	DiamondTrap c(a);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	a.whoAmI();
	a.takeDamage(50);
	a.attack("some one robot");
	a.guardGate();
	b.whoAmI();
	b.attack("some another robot");
	c.whoAmI();
	c.highFivesGuys();
	return (0);
}

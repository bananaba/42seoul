/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:16:05 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:16:06 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Foo;
	Zombie	*Goo;
	Zombie	*Hoo;

	Foo = zombieHorde(-1, "Foo");
	Goo = zombieHorde(0, "Goo");
	Hoo = zombieHorde(5, "Hoo");
	for (int i = 0; i < 5; i++)
		Hoo[i].announce();
	delete[] Hoo;
	return (0);
}

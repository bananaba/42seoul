/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:15:39 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:15:40 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Goo;
	Zombie	*Hoo;
	Zombie	*Joo;

	randomChump("Foo");
	Goo = newZombie("Goo");
	Hoo = newZombie("Hoo");
	delete	Goo;
	randomChump("Ioo");
	Joo = newZombie("Joo");
	delete	Joo;
	delete	Hoo;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:16:20 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:16:21 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie	*listZombie = new (std::nothrow) Zombie[N];
	if (listZombie == NULL)
	{
		std::cerr << "Error: Memory allocation fail" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
		listZombie[i].setName(name);
	return (listZombie);
}

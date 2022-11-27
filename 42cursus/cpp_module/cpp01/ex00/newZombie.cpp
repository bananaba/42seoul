/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:15:50 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:15:52 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie	*heapZombie = new (std::nothrow) Zombie (name);
	if (heapZombie == NULL)
	{
		std::cerr << "Error: Memory allocation fail" << std::endl;
		return (NULL);
	}
	heapZombie->announce();
	return (heapZombie);
}

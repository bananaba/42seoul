/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:22:11 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:22:12 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl		harl;
	std::string	level;

	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin >> std::ws, level);
		if (std::cin.eof())
		{
			std::cout << "EXIT" << std::endl;
			break ;
		}
		harl.complain(level);
	}
	return (0);
}

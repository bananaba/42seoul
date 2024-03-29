/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:22:05 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:22:06 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::etc(void)
{
	std::cerr << "Error: Undefined level" << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	int	i;
	int	lvIndex;

	i = 0;
	lvIndex = 0;
	while (i < 4)
	{
		lvIndex += (lv[i] == level) * (i + 1);
		i++;
	}
	(this->*f[lvIndex])();
}

Harl::Harl( void )
{
	lv[0] = "DEBUG";
	lv[1] = "INFO";
	lv[2] = "WARNING";
	lv[3] = "ERROR";
	f[0] = &Harl::etc;
	f[1] = &Harl::debug;
	f[2] = &Harl::info;
	f[3] = &Harl::warning;
	f[4] = &Harl::error;
}

Harl::~Harl( void )
{}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:22:18 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:22:19 by balee            ###   ########.fr       */
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

void	Harl::harlFilter( std::string level )
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
	switch (lvIndex)
	{
		case 1:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*f[1])();
			std::cout << std::endl;
		case 2:
			std::cout << "[ INFO ]" << std::endl;
			(this->*f[2])();
			std::cout << std::endl;
		case 3:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*f[3])();
			std::cout << std::endl;
		case 4:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*f[4])();
			std::cout << std::endl;
			break ;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:28:09 by balee             #+#    #+#             */
/*   Updated: 2022/11/22 19:17:23 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	cmd;
	int			i;

	i = 0;
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin >> std::ws, cmd);
		if (std::cin.eof())
			break ;
		else if (cmd.compare("ADD") == 0)
		{
			book.add(i);
			i = (i + 1) % 8;
		}
		else if (cmd.compare("SEARCH") == 0)
			book.search();
		else if (cmd.compare("EXIT") == 0)
			break ; 
	}
	return (0);
}

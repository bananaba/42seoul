/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:28:12 by balee             #+#    #+#             */
/*   Updated: 2022/11/24 19:53:14 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add(int i)
{
	info[i].add();
}

void	PhoneBook::search(void)
{
	int					i;
	std::string			index;
	std::stringstream	ss;

	i = 0;
	if (info[0].is_empty())
	{
		std::cout << "The PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << std::right << std::setw(10) << "index" << "|"
		<< std::right << std::setw(10) << "first name" << "|"
		<< std::right << std::setw(10) << "last name" << "|"
		<< std::right << std::setw(10) << "nickname" << std::endl;
	while (info[i].print_info(i))
		i++;
	while (true)
	{
		std::cout << "Index : ";
		std::getline(std::cin >> std::ws, index);
		ss.str(index);
		ss >> i;
		if (std::cin.eof())
			break ;
		else if (ss.fail() || i < 0 || i >= 8 || info[i].is_empty())
		{
			std::cout << "The index is out of range or wrong" << std::endl;
			ss.clear();
		}
		else
		{
			info[i].print_index();
			break ;
		}
	}
}

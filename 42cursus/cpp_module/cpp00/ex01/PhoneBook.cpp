/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:28:12 by balee             #+#    #+#             */
/*   Updated: 2022/11/22 16:55:48 by balee            ###   ########.fr       */
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
		if (ss.fail() || i < 0 || i >= 8 || info[i].is_empty())
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

void	Contact::add(void)
{
	std::cout << std::left << std::setw(15) << "First Name" << ": ";
	std::getline(std::cin >> std::ws, _firstName);
	std::cout << std::left << std::setw(15) << "Last Name" << ": ";
	std::getline(std::cin >> std::ws, _lastName);
	std::cout << std::left << std::setw(15) << "Nick Name" << ": ";
	std::getline(std::cin >> std::ws, _nickName);
	std::cout << std::left << std::setw(15) << "Phone Number" << ": ";
	std::getline(std::cin >> std::ws, _phoneNumber);
	std::cout << std::left << std::setw(15) << "Secret" << ": ";
	std::getline(std::cin >> std::ws, _darkestSecret);
}

bool	Contact::print_info(int i)
{
	if (_firstName.empty())
		return (false);
	std::cout << std::right << std::setw(10) << i  << "|";
	if (_firstName.length() <= 10)
		std::cout << std::right << std::setw(10) << _firstName << "|";
	else
		std::cout << _firstName.substr(0, 9) << "." << "|";
	if (_lastName.length() <= 10)
		std::cout << std::right << std::setw(10) << _lastName << "|";
	else
		std::cout << _lastName.substr(0, 9) << "." << "|";
	if (_nickName.length() <= 10)
		std::cout << std::right << std::setw(10) << _nickName << std::endl;
	else
		std::cout << _nickName.substr(0, 9) << "." << std::endl;
	return (true);
}

bool	Contact::is_empty(void)
{
	if (_firstName.empty())
		return (true);
	return (false);
}

void	Contact::print_index(void)
{
	std::cout << std::left << std::setw(15) << "First name" << ": " << _firstName << std::endl;
	std::cout << std::left << std::setw(15) << "Last name" << ": " << _lastName << std::endl;
	std::cout << std::left << std::setw(15) << "Nick name" << ": " << _nickName << std::endl;
	std::cout << std::left << std::setw(15) << "Phone number" << ": " << _phoneNumber << std::endl;
	std::cout << std::left << std::setw(15) << "Darkest secret" << ": " << _darkestSecret << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:29:03 by balee             #+#    #+#             */
/*   Updated: 2022/11/22 19:29:05 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	_firstName = "";
	_lastName = "";
	_nickName = "";
	_phoneNumber = "";
	_darkestSecret = "";
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
	if (i > 7 || _firstName.empty())
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

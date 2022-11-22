/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:28:14 by balee             #+#    #+#             */
/*   Updated: 2022/11/22 16:28:29 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		Contact(void)
		{
			_firstName = "";
			_lastName = "";
			_nickName = "";
			_phoneNumber = "";
			_darkestSecret = "";
		}
		~Contact(void) {}
		void	add(void);
		bool	print_info(int i);
		bool	is_empty(void);
		void	print_index(void);
};

class PhoneBook
{
	private:
		Contact info[8];
	public:
		PhoneBook(void) {}
		~PhoneBook(void) {}
		void	add(int i);
		void	search(void);
};

#endif
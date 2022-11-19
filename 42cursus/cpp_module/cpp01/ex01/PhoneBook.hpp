#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact(void)
		{
			first_name = "";
			last_name = "";
			nickname = "";
			phone_number = "";
			darkest_secret = "";
		}
		~Contact(void) {}
		void	add(void);
		int		print_info(int i);
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

void	PhoneBook::add(int i)
{
	info[i].add();
}

void	PhoneBook::search(void)
{
	int	i;

	i = 0;
	std::cout << std::right << std::setw(10) << "index" << "|"
		<< std::right << std::setw(10) << "first name" << "|"
		<< std::right << std::setw(10) << "last name" << "|"
		<< std::right << std::setw(10) << "nickname" << std::endl;
	while (info[i].print_info(i))
		i++;
	while (true)
	{
		std::cout << "> ";
		std::cin >> i;
		if (std::cin.fail())
		{
			std::cin.clear();
		}
	}
}

void	Contact::add(void)
{
	std::cout << std::left << std::setw(15) << "first_name" << ": ";
	std::getline(std::cin >> std::ws, first_name);
	std::cout << std::left << std::setw(15) << "last_name" << ": ";
	std::getline(std::cin >> std::ws, last_name);
	std::cout << std::left << std::setw(15) << "nickname" << ": ";
	std::getline(std::cin >> std::ws, nickname);
	std::cout << std::left << std::setw(15) << "phone_number" << ": ";
	std::getline(std::cin >> std::ws, phone_number);
	std::cout << std::left << std::setw(15) << "secret" << ": ";
	std::getline(std::cin >> std::ws, darkest_secret);
}

int	Contact::print_info(int i)
{
	if (first_name.empty())
		return (false);
	std::cout << std::right << std::setw(10) << i + 1  << "|";
	if (first_name.length() <= 10)
		std::cout << std::right << std::setw(10) << first_name << "|";
	else
		std::cout << first_name.substr(0, 9) << "." << "|";
	if (last_name.length() <= 10)
		std::cout << std::right << std::setw(10) << last_name << "|";
	else
		std::cout << last_name.substr(0, 9) << "." << "|";
	if (nickname.length() <= 10)
		std::cout << std::right << std::setw(10) << nickname << std::endl;
	else
		std::cout << nickname.substr(0, 9) << "." << std::endl;
	return (true);
}

#endif
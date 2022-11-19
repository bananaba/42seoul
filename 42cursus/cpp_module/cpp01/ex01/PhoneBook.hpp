#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		phonebook(/* args */);
		~phonebook();
	};

	phonebook::phonebook(/* args */)
	{
	}

	phonebook::~phonebook()
	{
}


#endif

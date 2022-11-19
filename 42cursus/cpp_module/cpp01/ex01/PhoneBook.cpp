#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	info[8];
	std::string	cmd;
	int			i;

	while (true)
	{
		std::cout << ">";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			;
		else if (cmd == "SEARCH")
			;
		else if (cmd == "EXIT")
			;
	}
	return (0);
}

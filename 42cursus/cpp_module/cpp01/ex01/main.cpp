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
		if (cmd.compare("ADD") == 0)
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

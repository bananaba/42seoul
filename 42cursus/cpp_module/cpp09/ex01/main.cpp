#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage: ./RPN arg" << std::endl;
		return (1);
	}
	return (reversePolishNotation(argv[1]));
}

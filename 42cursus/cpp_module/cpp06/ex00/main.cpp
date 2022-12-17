#include "Scalar.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Error: no argument" << std::endl;
		return (1);
	}

	Scalar::convert(argv[1]);

	return (0);
}
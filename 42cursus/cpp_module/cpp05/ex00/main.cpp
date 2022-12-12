#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bureaucrat;
		std::cout << bureaucrat << std::endl;
		// Bureaucrat bureaucrat("balee", 0);
		// Bureaucrat bureaucrat("balee", 151);

		// Bureaucrat bureaucrat("balee");
		// std::cout << bureaucrat << std::endl;
		// bureaucrat.incrementGrade();
		// std::cout << bureaucrat << std::endl;
		// bureaucrat.decrementGrade();
		// std::cout << bureaucrat << std::endl;
		// bureaucrat.decrementGrade();
		// std::cout << bureaucrat << std::endl;

		// Bureaucrat bureaucrat("balee", 1);
		// std::cout << bureaucrat << std::endl;
		// bureaucrat.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

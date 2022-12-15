#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat				human("balee", 1);
		ShrubberyCreationForm	shrubbery("t1");
		RobotomyRequestForm		robotomy("t2");
		PresidentialPardonForm	pardon("t3");

		std::cout << human << std::endl;
		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;

		shrubbery.beSigned(human);
		robotomy.beSigned(human);
		pardon.beSigned(human);

		human.signForm(shrubbery);
		human.signForm(robotomy);
		human.signForm(pardon);

		shrubbery.execute(human);
		robotomy.execute(human);
		pardon.execute(human);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
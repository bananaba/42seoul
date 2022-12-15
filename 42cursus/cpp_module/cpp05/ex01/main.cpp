#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	balee("balee", 10);
	Form		form("form", 10, 10);

	try
	{
		std::cout << balee << std::endl;
		std::cout << form << std::endl;
		balee.decrementGrade();
		balee.signForm(form);
		balee.incrementGrade();
		balee.signForm(form);
		balee.signForm(form);
		std::cout << form << std::endl;
		
		Form	form_err(151, 151);
		std::cout << "\nTest Finish" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
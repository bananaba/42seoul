#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern	someRandomIntern;
	AForm*	rrf;
	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		// rrf = someRandomIntern.makeForm("wrongForm", "balee");
		std::cout << rrf->getName() << std::endl;
		std::cout << rrf->getTarget() << std::endl;

		std::cout << *rrf << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
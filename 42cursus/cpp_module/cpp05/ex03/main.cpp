/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:18:35 by balee             #+#    #+#             */
/*   Updated: 2022/12/16 17:46:34 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern		someRandomIntern;
	AForm*		rrf;
	Bureaucrat	human("balee", 1);

	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		// rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		// rrf = someRandomIntern.makeForm("wrongForm", "balee");
		std::cout << rrf->getName() << std::endl;
		std::cout << rrf->getTarget() << std::endl;
		std::cout << *rrf << std::endl;

		rrf->beSigned(human);
		human.signForm(*rrf);
		rrf->execute(human);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
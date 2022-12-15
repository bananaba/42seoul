/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:17:32 by balee             #+#    #+#             */
/*   Updated: 2022/12/15 16:40:47 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		// AForm *temp1 = new ShrubberyCreationForm("temp1");
		// AForm *temp2 = new RobotomyRequestForm("temp2");

		// std::cout << *temp1 << std::endl;
		// std::cout << *temp2 << std::endl;
		// *temp2 = *temp1;
		// std::cout << *temp2 << std::endl;

		// delete temp1;
		// delete temp2;

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
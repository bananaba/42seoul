/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:17:12 by balee             #+#    #+#             */
/*   Updated: 2022/12/17 13:13:23 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	balee("balee", 10);
	Form		form("form", 10, 10);
	Form		temp;

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

		temp = form;
		std::cout << temp << std::endl;
		
		Form	form_err(151, 151);
		std::cout << "\nTest Finish" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
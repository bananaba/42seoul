/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:08:11 by balee             #+#    #+#             */
/*   Updated: 2022/12/17 16:41:00 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate()
{
	std::srand(time(NULL));

	switch (rand() % 3)
	{
		case 0:
			std::cout << "generated an A class" << std::endl;
			return (new A);
		case 1:
			std::cout << "generated an B class" << std::endl;
			return (new B);
		case 2:
			std::cout << "generated an C class" << std::endl;
			return (new C);
	}

	std::cerr << "Undefined error in 'generate' function" << std::endl;
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Undefined class" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception & e) {}

	try
	{
		B	&b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception & e) {}

	try
	{
		C	&c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception & e) {}

	std::cout << "Undefined class" << std::endl;
}

int	main()
{
	Base	*base;

	base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}

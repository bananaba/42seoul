/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:18:29 by balee             #+#    #+#             */
/*   Updated: 2022/12/16 17:45:09 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	// std::cout << "Intern Default Constructor called" << std::endl;
	form[0] = new ShrubberyCreationForm("none");
	form[1] = new RobotomyRequestForm("none");
	form[2] = new PresidentialPardonForm("none");
}

Intern::Intern( const Intern & src )
{
	// std::cout << "Intern copy Constructor called" << std::endl;
	form[0] = new ShrubberyCreationForm(src.form[0]->getTarget());
	form[1] = new RobotomyRequestForm(src.form[1]->getTarget());
	form[2] = new PresidentialPardonForm(src.form[2]->getTarget());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	for (int i = 0; i < 3; i++)
		delete form[i];
	// std::cout << "Intern destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	// std::cout << "Intern Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		for (int i = 0; i < 3; i++)
			*this->form[i] = *rhs.form[i];
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AForm	*Intern::makeForm(std::string Name, std::string Target)
{
	int	info;

	info = 0;
	for (int i = 0; i < 3; i++)
	{
		form[i]->setTarget(Target);
		info = (info << 1) | (Name == form[i]->getName());
	}
	switch (info)
	{
		case 0b100:
			return (form[0]);
		case 0b010:
			return (form[1]);
		case 0b001:
			return (form[2]);
		default:
			throw Intern::UnknownForm();
	}
}

const char	*Intern::UnknownForm::what() const throw()
{
	return ("Form name doesn't exist");
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
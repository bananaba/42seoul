/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:17:47 by balee             #+#    #+#             */
/*   Updated: 2022/12/15 16:17:48 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(): AForm("robotomy request", "none", 72, 45) 
{
	// std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target): AForm("robotomy request", target, 72, 45) 
{
	// std::cout << "RobotomyRequestForm Conversion constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
{
	// std::cout << "RobotomyRequestForm copy Constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	// std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		AForm::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << i.getName() << ", target : " << i.getTarget() << ", signed : " << std::boolalpha
		<< i.getSigned() << std::noboolalpha << ", sign grade : " << i.getGradeToSign()
		<< ", execute grade : "<< i.getGradeToExecute() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (getSigned() == false)
		throw AForm::NotSignedException();
	else if (getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else
		this->robotomize();
}

void RobotomyRequestForm::robotomize(void) const
{
	std::srand(std::time(NULL));

	std::cout << "Drrrrrrrr... Drrrrrr... Drr!" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has become a robot." << std::endl;
	else
		std::cout << this->getTarget() << " robotomization fall!" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
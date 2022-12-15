/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:18:21 by balee             #+#    #+#             */
/*   Updated: 2022/12/15 16:18:22 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	// std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	// std::cout << "Bureaucrat copy Constructor called" << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(std::string const name): _name(name), _grade(150)
{
	// std::cout << "Bureaucrat Conversion constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int const grade): _name("default")
{
	// std::cout << "Bureaucrat Conversion constructor called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string const name, int const grade): _name(name)
{
	// std::cout << "Bureaucrat Normal constructor called" << std::endl;
	this->setGrade(grade);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	// std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->setName(rhs.getName());
		this->setGrade(rhs.getGrade());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

void		Bureaucrat::signForm(AForm & aform)
{
	try
	{
		aform.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << aform.getName()
			<< " because " << this->getName() << "'s " << e.what() << "." << std::endl;
	}
}

void 		Bureaucrat::executeForm(AForm const &form)
{
	try 
	{
		form.execute(*this);
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::setName(std::string const name)
{
	const_cast<std::string &>(this->_name) = name;
}

void		Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

void		Bureaucrat::incrementGrade(void)
{
	this->setGrade(this->getGrade() - 1);
}

void		Bureaucrat::decrementGrade(void)
{
	this->setGrade(this->getGrade() + 1);
}


/* ************************************************************************** */
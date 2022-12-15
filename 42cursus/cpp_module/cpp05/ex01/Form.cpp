/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:17:04 by balee             #+#    #+#             */
/*   Updated: 2022/12/15 16:17:05 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form( const Form & src ): _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form copy Constructor called" << std::endl;
	*this = src;
}

Form::Form(std::string const name): _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form Conversion constructor called" << std::endl;
}

Form::Form(int const gradeToSign, int const gradeToExecute): _name("default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form Normal constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form Normal constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "Form destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	std::cout << "Form Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->setName(rhs.getName());
		this->setSigned(rhs.getSigned());
		this->setGradeToSign(rhs.getGradeToSign());
		this->setGradeToExecute(rhs.getGradeToExecute());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << i.getName() << ", signed : " << std::boolalpha << i.getSigned() << std::noboolalpha << ", sign grade : " << i.getGradeToSign() << ", execute grade : "<< i.getGradeToExecute() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

void	Form::beSigned(Bureaucrat const & rhs)
{
	if (this->getSigned() == true)
		std::cout << rhs.getName() << " couldn't sign " << this->getName()
			<< " because " << this->getName() << " already signed" << std::endl;
	else if (rhs.getGrade() > this->getGradeToExecute() || rhs.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	else
	{
		this->setSigned(true);
		std::cout << rhs.getName() << " signed " << this->getName() << std::endl;
	}
		
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool		Form::getSigned(void) const
{
	return (this->_signed);
}

int			Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int			Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void		Form::setName(std::string const name)
{
	const_cast<std::string &>(this->_name) = name;
}

void		Form::setSigned(bool sign)
{
	this->_signed = sign;
}

void		Form::setGradeToSign(int const gradeToSign)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150)
		throw Form::GradeTooLowException();
	else
		const_cast<int &>(this->_gradeToSign) = gradeToSign;
}

void		Form::setGradeToExecute(int const gradeToExecute)
{
	if (gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else
		const_cast<int &>(this->_gradeToExecute) = gradeToExecute;
}


/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:18:55 by balee             #+#    #+#             */
/*   Updated: 2022/12/15 16:19:48 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shrubbery creation", "none", 145, 137) 
{
	// std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target): AForm("shrubbery creation", target, 145, 137) 
{
	// std::cout << "ShrubberyCreationForm Conversion constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
{
	// std::cout << "ShrubberyCreationForm copy Constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	// std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		AForm::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << i.getName() << ", target : " << i.getTarget() << ", signed : " << std::boolalpha
		<< i.getSigned() << std::noboolalpha << ", sign grade : " << i.getGradeToSign()
		<< ", execute grade : "<< i.getGradeToExecute() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (getSigned() == false)
		throw AForm::NotSignedException();
	else if (getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else
		this->makeTree();
}

void	ShrubberyCreationForm::makeTree(void) const
{
	std::ofstream	ofs(getTarget() + "_shrubbery", std::ios_base::out | std::ios_base::trunc);
	if (ofs.fail())
		throw AForm::TargetOpenFailException();

	ofs << 	"                                                         .\n"
			"                                              .         ;\n"
			"                 .              .              ;%     ;;\n"
			"                   ,           ,                :;%  %;\n"
			"                    :         ;                   :;%;'     .,\n"
			"           ,.        %;     %;            ;        %;'    ,;\n"
			"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
			"              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
			"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
			"                `%;.     ;%;     %;'         `;%%;.%;'\n"
			"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
			"                    `:%;.  :;bd%;          %;@%;'\n"
			"                      `@%:.  :;%.         ;@@%;'\n"
			"                        `@%.  `;@%.      ;@@%;\n"
			"                          `@%%. `@%%    ;@@%;\n"
			"                            ;@%. :@%%  %@@%;\n"
			"                              %@bd%%%bd%%:;\n"
			"                                #@%%%%%:;;\n"
			"                                %@@%%%::;\n"
			"                                %@@@%(o);  . '\n"
			"                                %@@@o%;:(.,'\n"
			"                            `.. %@@@o%::;\n"
			"                               `)@@@o%::;\n"
			"                                %@@(o)::;\n"
			"                               .%@@@@%::;\n"
			"                               ;%@@@@%::;.\n"
			"                              ;%@@@@%%:;;;.\n"
			"                          ...;%@@@@@%%:;;;;,.." << std::endl;

	ofs.close();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:08:06 by balee             #+#    #+#             */
/*   Updated: 2022/12/15 01:40:55 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): Animal()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->setType("Cat");
	this->brain = new Brain();
}

Cat::Cat( const Cat & src ): Animal(src)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->setType(src.getType());
	this->brain = new Brain(*src.brain);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete	this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->setType(rhs.getType());
		*this->brain = *rhs.brain;
	}
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Type = " << i.getType();
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::makeSound(void) const
{
	std::cout << "Miauuuuu" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain	*Cat::getBrain(void) const
{
	return (this->brain);
}


/* ************************************************************************** */
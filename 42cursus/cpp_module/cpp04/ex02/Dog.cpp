/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:08:14 by balee             #+#    #+#             */
/*   Updated: 2022/12/15 02:00:55 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): Animal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->setType("Dog");
	this->brain = new Brain();
}

Dog::Dog( const Dog & src ): Animal(src)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->setType(src.getType());
	this->brain = new Brain(*src.brain);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete	this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->setType(rhs.getType());
		*this->brain = *rhs.brain;
	}
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << "Type = " << i.getType();
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound(void) const
{
	std::cout << "Guauuuuu" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain	*Dog::getBrain(void) const
{
	return (this->brain);
}


/* ************************************************************************** */
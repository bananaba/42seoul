/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:07:53 by balee             #+#    #+#             */
/*   Updated: 2022/12/12 15:30:15 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal( const Animal & src )
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->setType(rhs.getType());
	}
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << "Type = " << i.getType();
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Animal::getType(void) const
{
	return (this->type);
}

void			Animal::setType(std::string const _type)
{
	this->type = _type;
}

/* ************************************************************************** */
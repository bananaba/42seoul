/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:29 by balee             #+#    #+#             */
/*   Updated: 2022/12/12 15:27:29 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice(): AMateria("ice")
{
	// std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice( const Ice & src )
{
	// std::cout << "Ice copy constructor called." << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	// std::cout << "Ice destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs )
{
	// std::cout << "Ice Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->AMateria::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Ice const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


/* ************************************************************************** */
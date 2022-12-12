/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:33 by balee             #+#    #+#             */
/*   Updated: 2022/12/12 15:27:34 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ICharacter::ICharacter()
{
	// std::cout << "ICharacter Default constructor called" << std::endl;
}

ICharacter::ICharacter( const ICharacter & src )
{
	// std::cout << "ICharacter copy constructor called." << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ICharacter::~ICharacter()
{
	// std::cout << "ICharacter destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ICharacter &				ICharacter::operator=( ICharacter const & rhs )
{
	// std::cout << "ICharacter Copy assignment operator called" << std::endl;
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ICharacter const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
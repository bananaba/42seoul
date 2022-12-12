/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:39 by balee             #+#    #+#             */
/*   Updated: 2022/12/12 15:27:40 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

IMateriaSource::IMateriaSource()
{
	// std::cout << "IMateriaSource Default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource( const IMateriaSource & src )
{
	// std::cout << "IMateriaSource copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

IMateriaSource::~IMateriaSource()
{
	// std::cout << "IMateriaSource destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

IMateriaSource &				IMateriaSource::operator=( IMateriaSource const & rhs )
{
	// std::cout << "IMateriaSource Copy assignment operator called" << std::endl;
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, IMateriaSource const & i )
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
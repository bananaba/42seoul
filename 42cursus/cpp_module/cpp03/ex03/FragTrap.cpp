/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:47:22 by balee             #+#    #+#             */
/*   Updated: 2022/12/08 16:47:23 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	_name = "FRTP";
	_hitPoint = 100;
	_maxHitPoint = _hitPoint;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string const name): ClapTrap(name)
{
	std::cout << "FragTrap " << name << "'s Constructor called" << std::endl;
	_name = name;
	_hitPoint = 100;
	_maxHitPoint = _hitPoint;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap( const FragTrap & src ): ClapTrap(src)
{
	std::cout << "FragTrap " << src.getName() << "'s Copy Constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << "'s Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_hitPoint = rhs.getHitPoint();
		this->_energyPoint = rhs.getEnergyPoint();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	o << std::setw(15) << "Name = " << i.getName() << std::endl;
	o << std::setw(15) << "HitPoint = " << i.getHitPoint() << std::endl;
	o << std::setw(15) << "EnergyPoint = " << i.getEnergyPoint() << std::endl;
	o << std::setw(15) << "AttackDamage = " << i.getAttackDamage() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	FragTrap::highFivesGuys(void)
{
	if (this->getHitPoint() == 0)
		std::cout << "FragTrap " << this->getName() << " was already dead!" << std::endl;
	else if (this->getEnergyPoint() == 0)
		std::cout << "FragTrap " << this->getName() << " has no energy point left!" << std::endl;
	else
	{
		std::cout << "FragTrap " << this->getName() << ": High Fives guys!" << std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
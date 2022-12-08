#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
	_name = "CLTP";
	_hitPoint = 10;
	_maxHitPoint = _hitPoint;
	_energyPoint = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string const name)
{
	std::cout << "ClapTrap " << name << "'s Constructor called" << std::endl;
	_name = name;
	_hitPoint = 10;
	_maxHitPoint = _hitPoint;
	_energyPoint = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "ClapTrap " << src.getName() << "'s Copy Constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->getName() << "'s Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_hitPoint = rhs.getHitPoint();
		this->_energyPoint = rhs.getEnergyPoint();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
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

void	ClapTrap::attack(const std::string& target)
{
	if (this->getHitPoint() == 0)
		std::cout << "ClapTrap " << this->getName() << " was already dead!" << std::endl;
	else if (this->getEnergyPoint() == 0)
		std::cout << "ClapTrap " << this->getName() << " has no energy point left!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoint() == 0)
		std::cout << "ClapTrap " << this->getName() << " was already dead!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->getName() << " take " << amount << " damage!" << std::endl;
		if (this->getHitPoint() > amount)
			this->setHitPoint(this->getHitPoint() - amount);
		else
		{
			this->setHitPoint(0);
			std::cout << "ClapTrap " << this->getName() << " die!" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoint() == 0)
		std::cout << "ClapTrap " << this->getName() << " was already dead!" << std::endl;
	else if (this->getEnergyPoint() == 0)
		std::cout << "ClapTrap " << this->getName() << " has no energy point left!" << std::endl;
	else if (this->getHitPoint() == this->getMaxHitPoint())
		std::cout << "ClapTrap " << this->getName() << "'s HitPoint was aleady max!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->getName() << " is repaired " << amount << " point!" << std::endl;
		if (this->getHitPoint() + amount < this->getMaxHitPoint())
			this->setHitPoint(this->getHitPoint() + amount);
		else
		{
			this->setHitPoint(this->getMaxHitPoint());
			std::cout << "ClapTrap " << this->getName() << "'s HitPoint is max!" << std::endl;
		}
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int			ClapTrap::getHitPoint(void) const
{
	return (this->_hitPoint);
}

unsigned int			ClapTrap::getMaxHitPoint(void) const
{
	return (this->_maxHitPoint);
}

unsigned int			ClapTrap::getEnergyPoint(void) const
{
	return (this->_energyPoint);
}

unsigned int			ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void		ClapTrap::setName(std::string const name)
{
	std::cout << "ClapTrap " << this->getName() << "'s name is set to " << name << std::endl;
	this->_name = name;
}

void		ClapTrap::setHitPoint(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName() << "'s HitPoint is set from " << this->getHitPoint() << " to " << amount << std::endl;
	this->_hitPoint = amount;
}

void		ClapTrap::setEnergyPoint(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName() << "'s EnergyPoint is set from " << this->getEnergyPoint() << " to " << amount << std::endl;
	this->_energyPoint = amount;
}

void		ClapTrap::setAttackDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName() << "'s AttackDamage is set from " << this->getAttackDamage() << " to " << amount << std::endl;
	this->_attackDamage = amount;
}


/* ************************************************************************** */
#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	_name = "SCTP";
	_hitPoint = 100;
	_maxHitPoint = _hitPoint;
	_energyPoint = 50;
	_attackDamage = 20;
	_guardMode = false;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name)
{
	std::cout << "ScavTrap " << name << "'s Constructor called" << std::endl;
	_name = name;
	_hitPoint = 100;
	_maxHitPoint = _hitPoint;
	_energyPoint = 50;
	_attackDamage = 20;
	_guardMode = false;
}

ScavTrap::ScavTrap( const ScavTrap & src ): ClapTrap(src)
{
	std::cout << "ScavTrap " << src.getName() << "'s Copy Constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << "'s Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_hitPoint = rhs.getHitPoint();
		this->_energyPoint = rhs.getEnergyPoint();
		this->_attackDamage = rhs.getAttackDamage();
		this->_guardMode = rhs.getGuardMode();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
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

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoint() == 0)
		std::cout << "ScavTrap " << this->getName() << " was already dead!" << std::endl;
	else if (this->getEnergyPoint() == 0)
		std::cout << "ScavTrap " << this->getName() << " has no energy point left!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->getHitPoint() == 0)
		std::cout << "ScavTrap " << this->getName() << " was already dead!" << std::endl;
	else if (this->getGuardMode() == false)
	{
		this->_guardMode = true;
		std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper Mode!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->getName() << " was already in Gate keeper Mode!" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

bool	ScavTrap::getGuardMode(void) const
{
	return (this->_guardMode);
}


/* ************************************************************************** */
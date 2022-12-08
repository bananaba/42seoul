#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap(), _name(ClapTrap::getName())
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	ClapTrap::_name += "_clap_name";
	this->_energyPoint = 50;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name), _name(ClapTrap::getName())
{
	std::cout << "DiamondTrap " << name << "'s Constructor called" << std::endl;
	ClapTrap::_name += "_clap_name";
	this->_energyPoint = 50;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ): ClapTrap(src), ScavTrap(src), FragTrap(src), _name(ClapTrap::getName())
{
	std::cout << "DiamondTrap " << src.getName() << "'s Copy Constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->getName() << "'s Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_hitPoint = rhs.getHitPoint();
		this->_energyPoint = rhs.getEnergyPoint();
		this->_attackDamage = rhs.getAttackDamage();
		ClapTrap::_name = rhs.getClapTrapName();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{
	o << std::setw(15) << "Name = " << i.getName() << std::endl;
	o << std::setw(15) << "ClapTrapName = " << i.getClapTrapName() << std::endl;
	o << std::setw(15) << "HitPoint = " << i.getHitPoint() << std::endl;
	o << std::setw(15) << "EnergyPoint = " << i.getEnergyPoint() << std::endl;
	o << std::setw(15) << "AttackDamage = " << i.getAttackDamage() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is '" << this->getName() << "' and ClapTrap name is '" << this->getClapTrapName() << "'!" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string				DiamondTrap::getName(void) const
{
	return (this->_name);
}

std::string				DiamondTrap::getClapTrapName(void) const
{
	return (ClapTrap::getName());
}


/* ************************************************************************** */
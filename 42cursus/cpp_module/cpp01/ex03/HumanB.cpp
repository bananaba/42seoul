#include "HumanB.hpp"

void	HumanB::attack(	void )
{
	if (bWeapon == NULL)
		std::cout << name << " attacks with no weapon" << std::endl;
	else
		std::cout << name << " attacks with their " << bWeapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &_weapon )
{
	bWeapon = &_weapon;
}

HumanB::HumanB( std::string _name )
{
	name = _name;
	bWeapon = NULL;
}

HumanB::~HumanB( void )
{}

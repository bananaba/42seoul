#include "HumanA.hpp"

void	HumanA::attack(	void )
{
	std::cout << name << " attacks with their " << aWeapon.getType() << std::endl;
}

HumanA::HumanA( std::string _name, Weapon &_weapon ) : aWeapon(_weapon)
{
	name = _name;
}

HumanA::~HumanA( void )
{}

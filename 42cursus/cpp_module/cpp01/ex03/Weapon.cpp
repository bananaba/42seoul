#include "Weapon.hpp"

const std::string	&Weapon::getType( void )
{
	std::string	&typeREF = type;
	return (typeREF);
}

void	Weapon::setType( std::string _type )
{
	type = _type;
}

Weapon::Weapon( void )
{
	type = "";
}

Weapon::Weapon( std::string _type )
{
	type = _type;
}

Weapon::~Weapon( void )
{}

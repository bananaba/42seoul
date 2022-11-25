#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		*bWeapon;
		HumanB( void );
	public:
		void	attack(	void );
		void	setWeapon( Weapon &_weapon );
		HumanB( std::string _name );
		~HumanB( void );
};

#endif

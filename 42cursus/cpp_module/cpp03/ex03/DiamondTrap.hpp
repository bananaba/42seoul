#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{

	public:

		DiamondTrap();
		DiamondTrap( DiamondTrap const & src );
		DiamondTrap(std::string name);
		~DiamondTrap();

		DiamondTrap &		operator=( DiamondTrap const & rhs );

		void	attack(const std::string& target);
		void	whoAmI(void);

		std::string		getName(void) const;
		std::string		getClapTrapName(void) const;

	private:

		std::string		_name;

};

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i );

#endif /* ***************************************************** DIAMONDTRAP_H */
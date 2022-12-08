#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{

	public:

		ScavTrap();
		ScavTrap( ScavTrap const & src );
		ScavTrap(std::string const name);
		virtual	~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );

		virtual void	attack(const std::string& target);
		void			guardGate(void);

		bool			getGuardMode(void) const;

	private:
		bool	_guardMode;


};

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i );

#endif /* ******************************************************** SCAVTRAP_H */
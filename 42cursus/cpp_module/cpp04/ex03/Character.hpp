#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter
{

	public:

		Character(std::string const name);
		Character( Character const & src );
		~Character();

		Character &		operator=( Character const & rhs );

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

		std::string const &	getName() const;

	private:

		Character();
		std::string	_name;
		AMateria	*_inventory[4];

};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */
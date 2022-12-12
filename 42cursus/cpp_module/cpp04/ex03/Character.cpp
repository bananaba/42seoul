#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(std::string const name): _name(name)
{
	// std::cout << "Character Conversion constructor called" << std::endl;
	for (int idx = 0; idx < 4; idx++)
		_inventory[idx] = NULL;
}

Character::Character( const Character & src )
{
	// std::cout << "Character copy constructor called." << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	// std::cout << "Character destructor called." << std::endl;
	for (int idx = 0; idx < 4; idx++)
	{
		if (this->_inventory[idx] != NULL)
		{
			delete this->_inventory[idx];
			_inventory[idx] = NULL;
		}
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	// std::cout << "Character Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->~Character();
		this->_name = rhs.getName();
		for (int idx = 0; idx < 4; idx++)
		{
			if (this->_inventory[idx] != NULL)
				this->_inventory[idx] = rhs._inventory[idx]->clone();
			else
				_inventory[idx] = NULL;
		}
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << "Name = " << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int idx = 0; idx < 4; idx++)
	{
		if (this->_inventory[idx] == m)
		{
			std::cout << "* " << this->getName() << " already equips the item *" << std::endl;
			return ;
		}
		else if (this->_inventory[idx] == NULL)
		{
			std::cout << "* " << this->getName() << " equips " << m->getType() << " type item *" << std::endl;
			this->_inventory[idx] = m;
			return ;
		}
	}
	std::cout << "* No space in " << this->getName() << "’s inventory *" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "* Out of index *" << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << "* No item in " << this->getName() << "’s inventory " << idx << " *" << std::endl;
	else
	{
		std::cout << "*  " << this->getName() << "unequips " << this->_inventory[idx]->getType() << " type Item *" << std::endl;
		for (int i = idx; i < 3; i++)
			this->_inventory[i] = this->_inventory[i + 1];
		this->_inventory[3] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << "* Out of index *" << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << "* No item in " << this->getName() << "’s inventory " << idx << " *" << std::endl;
	else
		this->_inventory[idx]->use(target);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &	Character::getName() const
{
	return (this->_name);
}


/* ************************************************************************** */
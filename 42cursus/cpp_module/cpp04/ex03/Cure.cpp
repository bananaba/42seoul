#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure(): AMateria("cure")
{
	// std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure( const Cure & src )
{
	// std::cout << "Cure copy constructor called." << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	// std::cout << "Ice destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	// std::cout << "Cure Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->AMateria::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cure const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}



/* ************************************************************************** */
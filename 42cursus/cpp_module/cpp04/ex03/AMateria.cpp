#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria(): _type("default")
{
	// std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	// std::cout << "AMateria Conversion constructor called" << std::endl;
}

AMateria::AMateria( const AMateria & src )
{
	// std::cout << "AMateria copy constructor called." << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	// std::cout << "AMateria Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AMateria const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria used to " << target.getName() << " *" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &	AMateria::getType() const
{
	return (this->_type);
}


/* ************************************************************************** */
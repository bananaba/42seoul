#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource Conversion constructor called" << std::endl;
	for (int idx = 0; idx < 4; idx++)
		_materia[idx] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	// std::cout << "MateriaSource copy constructor called." << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor called." << std::endl;
	for (int idx = 0; idx < 4; idx++)
	{
		if (this->_materia[idx] != NULL)
		{
			delete this->_materia[idx];
			_materia[idx] = NULL;
		}
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	// std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->~MateriaSource();
		for (int idx = 0; idx < 4; idx++)
		{
			if (this->_materia[idx] != NULL)
				this->_materia[idx] = rhs._materia[idx]->clone();
			else
				_materia[idx] = NULL;
		}
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, MateriaSource const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		MateriaSource::learnMateria(AMateria *m)
{
	for (int idx = 0; idx < 4; idx++)
		if (this->_materia[idx] == NULL)
		{
			this->_materia[idx] = m;
			return ;
		}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int idx = 0; idx < 4; idx++)
		if (this->_materia[idx] != NULL && this->_materia[idx]->getType() == type)
			return (this->_materia[idx]->clone());
	return (NULL);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
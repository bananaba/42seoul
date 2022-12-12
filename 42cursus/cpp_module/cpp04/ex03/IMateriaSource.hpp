#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{

	public:

		IMateriaSource();
		IMateriaSource( IMateriaSource const & src );
		virtual	~IMateriaSource();

		IMateriaSource &		operator=( IMateriaSource const & rhs );

		virtual void	learnMateria(AMateria *) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;

	private:

};

std::ostream &			operator<<( std::ostream & o, IMateriaSource const & i );

#endif /* ************************************************** IMATERIASOURCE_H */
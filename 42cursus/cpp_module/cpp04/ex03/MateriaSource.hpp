/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:52 by balee             #+#    #+#             */
/*   Updated: 2022/12/12 15:27:53 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		MateriaSource &		operator=( MateriaSource const & rhs );

		void		learnMateria(AMateria *);
		AMateria*	createMateria(std::string const &);

	private:

		AMateria	*_materia[4];

};

std::ostream &			operator<<( std::ostream & o, MateriaSource const & i );

#endif /* *************************************************** MATERIASOURCE_H */
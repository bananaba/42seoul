/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:04 by balee             #+#    #+#             */
/*   Updated: 2022/12/12 15:27:10 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{

	public:

		AMateria();
		AMateria(std::string const & type);
		AMateria( AMateria const & src );
		virtual ~AMateria();

		AMateria &		operator=( AMateria const & rhs );

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

		std::string const &	getType() const;

	protected:

		std::string	_type;

};

std::ostream &			operator<<( std::ostream & o, AMateria const & i );

#endif /* ******************************************************** AMATERIA_H */
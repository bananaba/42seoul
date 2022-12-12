/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:26 by balee             #+#    #+#             */
/*   Updated: 2022/12/12 15:27:27 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{

	public:

		Cure();
		Cure( Cure const & src );
		~Cure();

		Cure &		operator=( Cure const & rhs );

		AMateria*	clone(void) const;
		void		use(ICharacter &target);

	private:

};

std::ostream &			operator<<( std::ostream & o, Cure const & i );

#endif /* ************************************************************ CURE_H */
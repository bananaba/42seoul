/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:31 by balee             #+#    #+#             */
/*   Updated: 2022/12/12 15:27:31 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{

	public:

		Ice();
		Ice( Ice const & src );
		~Ice();

		Ice &		operator=( Ice const & rhs );

		AMateria*	clone(void) const;
		void		use(ICharacter & target);

	private:

};

std::ostream &			operator<<( std::ostream & o, Ice const & i );

#endif /* ************************************************************* ICE_H */
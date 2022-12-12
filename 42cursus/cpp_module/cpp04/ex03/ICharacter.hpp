/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:36 by balee             #+#    #+#             */
/*   Updated: 2022/12/12 15:27:37 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>

class AMateria;

class ICharacter
{

	public:

		ICharacter();
		ICharacter( ICharacter const & src );
		virtual	~ICharacter();

		ICharacter &	operator=( ICharacter const & rhs );

		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;

		virtual std::string const &	getName() const = 0;

	private:

};

std::ostream &			operator<<( std::ostream & o, ICharacter const & i );

#endif /* ****************************************************** ICHARACTER_H */
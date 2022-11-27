/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:16:58 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:16:59 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		*bWeapon;
		HumanB( void );
	public:
		void	attack(	void );
		void	setWeapon( Weapon &_weapon );
		HumanB( std::string _name );
		~HumanB( void );
};

#endif

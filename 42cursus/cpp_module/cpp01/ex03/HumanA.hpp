/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:16:40 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:16:41 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		&aWeapon;
		HumanA( void );
	public:
		void	attack(	void );
		HumanA( std::string _name, Weapon &_weapon );
		~HumanA( void );
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:17:17 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:17:17 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		const std::string	&getType( void );
		void	setType( std::string _type );
		Weapon( void );
		Weapon( std::string _type );
		~Weapon( void );
};

#endif

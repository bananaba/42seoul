/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:27:44 by balee             #+#    #+#             */
/*   Updated: 2022/12/12 15:31:52 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter*	me = new Character("me");
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// me->unequip(2);
	// me->equip(tmp);
	// me->equip(tmp->clone());
	// me->equip(tmp->clone());
	// tmp = tmp->clone();
	// me->equip(tmp);
	ICharacter*	bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	// me->use(2, *bob);
	delete bob;
	delete me;
	delete src;
	// delete tmp;
	// system("leaks ex03");
	return 0;
}

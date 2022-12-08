/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:08:21 by balee             #+#    #+#             */
/*   Updated: 2022/12/08 17:12:48 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* animal[4];

	for (size_t i = 0; i < 4; i++)
	{
		if (i % 2)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}
	for (size_t i = 0; i < 4; i++)
		delete animal[i];

	const Animal * dog2 = new Dog();
	const Animal * dog1 = new Dog(*(static_cast<Dog const *>(dog2)));

	delete dog2;
	delete dog1;

	Dog	dog;
	Cat	cat;

	Dog dog_copy(dog);
	Cat cat_copy(cat);
	dog.setType("some special dog");
	cat.setType("some special cat");
	std::cout << "dog" << dog << std::endl;
	std::cout << "dog_copy" << dog_copy << std::endl;
	std::cout << "cat" << cat << std::endl;
	std::cout << "cat_copy" << cat << std::endl;

	// const Animal * animal = new Animal();
	return (0);
}

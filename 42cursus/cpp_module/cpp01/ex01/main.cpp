#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Foo;
	Zombie	*Goo;
	Zombie	*Hoo;

	Foo = zombieHorde(-1, "Foo");
	Goo = zombieHorde(0, "Goo");
	Hoo = zombieHorde(5, "Hoo");
	for (int i = 0; i < 5; i++)
		Hoo[i].announce();
	delete[] Hoo;
	return (0);
}

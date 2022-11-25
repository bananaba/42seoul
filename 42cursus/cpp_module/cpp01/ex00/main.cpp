#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Goo;
	Zombie	*Hoo;
	Zombie	*Joo;

	randomChump("Foo");
	Goo = newZombie("Goo");
	Hoo = newZombie("Hoo");
	delete	Goo;
	randomChump("Ioo");
	Joo = newZombie("Joo");
	delete	Joo;
	delete	Hoo;
	return (0);
}

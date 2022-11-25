#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie	*heapZombie = new (std::nothrow) Zombie (name);
	if (heapZombie == NULL)
		return (NULL);
	heapZombie->announce();
	return (heapZombie);
}

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie	*listZombie = new (std::nothrow) Zombie[N];
	if (listZombie == NULL)
		return (NULL);
	for (int i = 0; i < N; i++)
		listZombie[i].setName(name);
	return (listZombie);
}

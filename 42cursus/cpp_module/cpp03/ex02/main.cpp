#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
		FragTrap a;
		FragTrap b("FR4G-TP");

		a.highFivesGuys();
		a.attack("some one robot");
		a.takeDamage(101);
		a.takeDamage(1);
		a.attack("some another robot");
		// a.guardGate();
		b.highFivesGuys();
		// for(int i = 0; i < 101; i++)
		// 	b.attack("some the other robot");
	}
	return (0);
}
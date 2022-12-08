#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a;
	ClapTrap b("CL4P-TP");
	ClapTrap c(b);
	a.attack("some one robot");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some another robot");
	b.takeDamage(5);
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("some the other robot");
	b.beRepaired(3);
	b.beRepaired(3);
	return (0);
}

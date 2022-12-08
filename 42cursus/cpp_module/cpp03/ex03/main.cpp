#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a;
	DiamondTrap b("DI4D_TP");
	DiamondTrap c(a);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	a.whoAmI();
	a.takeDamage(50);
	a.attack("some one robot");
	a.guardGate();
	b.whoAmI();
	b.attack("some another robot");
	c.whoAmI();
	c.highFivesGuys();
	return (0);
}
#include "Point.hpp"

int	main(void)
{
	Point	a(5, 5);
	Point	b(2, 9);
	Point	c(0, 5);
	Point	p1(3, 7);
	Point	p2(4, 7);
	Point	p3(4, 5);

	std::cout << "Point a.x = " << a.getX() << " a.y = " << a.getY() << std::endl;
	std::cout << "Point b.x = " << b.getX() << " b.y = " << b.getY() << std::endl;
	std::cout << "Point c.x = " << c.getX() << " c.y = " << c.getY() << std::endl;
	std::cout << "Point p1.x = " << p1.getX() << " p1.y = " << p1.getY() << std::endl;
	std::cout << "Point p2.x = " << p2.getX() << " p2.y = " << p2.getY() << std::endl;
	std::cout << "Point p3.x = " << p3.getX() << " p3.y = " << p3.getY() << std::endl;
	if (bsp(a, b, c, p1))
		std::cout << "p is in the triangle" << std::endl;
	else
		std::cout << "p is out of the triangle" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "p2 is in the triangle" << std::endl;
	else
		std::cout << "p2 is out of the triangle" << std::endl;
	if (bsp(a, b, c, p3))
		std::cout << "p2 is in the triangle" << std::endl;
	else
		std::cout << "p2 is out of the triangle" << std::endl;
	return 0;
}

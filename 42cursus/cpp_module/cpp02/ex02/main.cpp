#include "Fixed.hpp"

int	main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	// std::cout << "\n42.42 > 42.42\n" << (Fixed(42.42f) > Fixed(42.42f)) << std::endl;
	// std::cout << "\n42.42 > 24.24\n" << (Fixed(42.42f) > Fixed(24.24f)) << std::endl;
	// std::cout << "\n24.24 > 42.42\n" << (Fixed(24.24f) > Fixed(42.42f)) << std::endl;
	// std::cout << "\n42.42 >= 42.42\n" << (Fixed(42.42f) >= Fixed(42.42f)) << std::endl;
	// std::cout << "\n42.42 == 42.42\n" << (Fixed(42.42f) == Fixed(42.42f)) << std::endl;
	// std::cout << "\n42.42 == 24.24\n" << (Fixed(42.42f) == Fixed(24.24f)) << std::endl;
	// std::cout << "\n42.42 != 42.42\n" << (Fixed(42.42f) != Fixed(42.42f)) << std::endl;
	// std::cout << "\n42.42 != 24.24\n" << (Fixed(42.42f) != Fixed(24.24f)) << std::endl;
	// std::cout << "\n42.42\n" << Fixed(42.42f) << std::endl;
	// std::cout << "\n42.42 + 42.42\n" << (Fixed(42.42f) + Fixed(42.42f)) << std::endl;
	// std::cout << "\n42.42 - 42.42\n" << (Fixed(42.42f) - Fixed(42.42f)) << std::endl;
	// std::cout << "\n42.42 * 42.42\n" << (Fixed(42.42f) * Fixed(42.42f)) << std::endl;
	// std::cout << "\n42.42 / 42.42\n" << (Fixed(42.42f) / Fixed(42.42f)) << std::endl;
	return (0);
}

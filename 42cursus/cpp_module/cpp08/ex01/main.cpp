#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	Span	sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
        std::vector<int>    l(10000);
		Span				span1(10000);
        std::srand(time (NULL));
        std::generate(l.begin(), l.end(), std::rand);

        span1.addRange(l.begin(), l.end());
		span1.addRange(l.begin(), l.end());

        std::cout << "Longest span: " << span1.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span1.shortestSpan() << std::endl;
		std::cout << span1.getSize() << std::endl;
		std::cout << span1.getCapacity() << std::endl;
        
		span1.addRange(l.begin(), l.end());
		span1.addNumber(42);
    }
	catch ( std::exception& e )
	{
        std::cout << e.what() << std::endl; 
    }

	try
	{
		Span	span2(10);
		span2.addNumber(1);
		std::cout << span2.shortestSpan() << std::endl;
		std::cout << span2.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
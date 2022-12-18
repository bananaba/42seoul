#include <deque>
#include <list>
#include "easyfind.hpp"

int main(void) {
	std::deque<int> d;
	std::list<char> l;
	std::vector<int> v;
	for (int i = 0 ; i < 10 ; ++i)
	{
		d.push_back(i);
		l.push_back(i + 'a');
		v.push_back(i);
	}
	try
	{
		std::deque<int>::iterator iter = easyfind(d, 3);
		std::cout << "Value " << 3 << " found on Index "
			<< std::distance(std::begin(d), iter) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::list<char>::iterator iter = easyfind(l, 6 + 'a');
		std::cout << "Value " << 6 + 'a' << " found on Index "
			<< std::distance(std::begin(l), iter) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator iter = easyfind(v, 10);
		std::cout << "Value " << 10 << " found on Index "
			<< std::distance(std::begin(v), iter) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

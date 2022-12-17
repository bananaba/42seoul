#include <iostream>
#include "iter.hpp"

int main(void)
{
	int			arr1[] = {1, 2, 3, 4, 5};
	char 		arr2[] = {'a', 'b', 'c', 'd', 'e'};
	std::string	arr3[] = {"aaa", "bbb", "ccc","ddd","eee"};

	::iter(arr1, 5, print);
	::iter(arr1, 5, increment);
	std::cout << std::endl;
	::iter(arr1, 5, print);

	std::cout << std::endl;
	::iter(arr2, 5, print);
	::iter(arr2, 5, increment);
	std::cout << std::endl;
	::iter(arr2, 5, print);

	std::cout << std::endl;
	::iter(arr3, 5, print);
}
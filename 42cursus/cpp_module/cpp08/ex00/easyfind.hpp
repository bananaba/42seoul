#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class ValueNotFound : public std::exception
{
	public:
		char const * what() const throw()
		{
			return ("Could't find the value in the container");
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator	iter;

	iter = std::find(container.begin(),container.end(), value);
	if (iter == container.end())
		throw ValueNotFound();
	return (iter);
}

#endif /* ******************************************************** EASYFIND_H */
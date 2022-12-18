#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _size(0)
{
	std::cout << "Span Default Constructor called" << std::endl;
}

Span::Span(unsigned int size) : _size(size)
{
	std::cout << "Span Conversion constructor called" << std::endl;
	_numbers.reserve(size);
}

Span::Span( const Span & src )
{
	std::cout << "Span copy Constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
	_numbers.clear();
	std::cout << "Span destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	std::cout << "Span Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_size = rhs._size;
		this->_numbers.clear();
		this->_numbers.reserve(this->_size);
		std::copy(rhs._numbers.begin(), rhs._numbers.end(), this->_numbers.begin());
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void 			Span::addNumber(int number)
{
	if (_numbers.size() >= this->_size)
		throw Span::AlreadyNElementException();
	_numbers.push_back(number);
}

void	Span::addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>			tmp(begin, end);
	std::vector<int>::iterator	iter = tmp.begin();
	long long					_capacity;

	_capacity = _size - _numbers.size();
	if (_numbers.size() == _size)
		throw Span::AlreadyNElementException();
	else if (static_cast<long long>(tmp.size()) > _capacity)
		for (unsigned int n = 0; n < _capacity; n++)
		{
			_numbers.push_back(*iter);
			iter++;
		}
	else
		copy(tmp.begin(), tmp.end(), std::back_inserter(this->_numbers));
}

unsigned int	Span::shortestSpan()
{
	int	prev;
	int	_shortestSpan = -1;

	if (_numbers.size() < 2)
		throw std::logic_error("Span size is too small");
	std::sort(_numbers.begin(), _numbers.end());
	for (std::vector<int>::iterator iter = _numbers.begin(); iter != _numbers.end(); iter++) 
	{
		if (iter == _numbers.begin()) 
			prev = *iter;
		else 
		{
			if (_shortestSpan == -1 || _shortestSpan > *iter - prev)
				_shortestSpan = *iter - prev;
			prev = *iter;
		}
	}
  return (_shortestSpan);
}

unsigned int	Span::longestSpan()
{
	unsigned int	_longestSpan;

	if (_numbers.size() < 2)
		throw std::logic_error("Span size is too small");
	_longestSpan = *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
	return (_longestSpan);
}

const char* Span::AlreadyNElementException::what() const throw()
{
	return ("There are already N elements!");
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int	Span::getSize(void) const
{
	return (this->_numbers.size());
}

unsigned int	Span::getCapacity(void) const
{
	return (this->_size);
}


/* ************************************************************************** */
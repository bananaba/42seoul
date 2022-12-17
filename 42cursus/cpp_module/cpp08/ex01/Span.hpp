#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{

	public:

		Span(unsigned int size);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		void			addNumber(int number);
		void			addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class AlreadyNElementException : public std::exception {
		public:
			const char *what(void) const throw();
		};

		unsigned int	getSize(void) const;
		unsigned int	getCapacity(void) const;

	private:

		Span();
		unsigned int		_size;
		std::vector<int>	_numbers;

};

#endif /* ************************************************************ SPAN_H */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:57:40 by balee             #+#    #+#             */
/*   Updated: 2022/12/17 16:53:30 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<typename T>
class Array
{
	public:
		Array() : _arr(new T[0]), _size(0)
		{
			std::cout << "Array Default Constructor called" << std::endl;
		}

		Array(unsigned int n) : _arr(new T[n]), _size(n)
		{
			std::cout << "Array Conversion Constructor called" << std::endl;
		}

		~Array()
		{
			if (this->_arr != NULL)
			{
				delete [] _arr;
				_arr = NULL;
			}
			std::cout << "Array destructor called." << std::endl;
		}

		Array( Array const &target ) : _arr(NULL)
		{
			std::cout << "Array copy Constructor called" << std::endl;
			*this = target;
		}

		Array &			operator=( Array const & target )
		{
			std::cout << "Array Copy assignment operator called" << std::endl;
			if (this != &target)
			{
				if (this->_arr != NULL)
					delete [] _arr;
				this->_arr = new T [target.size()];
				this->_size = target.size();
				for (unsigned int i = 0; i < this->_size; i++)
					this->_arr[i] = target._arr[i];
				
			}
			return (*this);
		};

		T &				operator[]( long long _idx )
		{
			if (_idx >= this->_size || _idx < 0)
				throw std::out_of_range("Index out of range");
			return (_arr[_idx]);
		}

		const T &		operator[]( long long _idx ) const
		{
			if (_idx >= this->_size || _idx < 0)
				throw std::out_of_range("Index out of range");
			return (_arr[_idx]);
		}

		unsigned int	size(void) const
		{
			return (this->_size);
		}

	private:

		T				*_arr;
		unsigned int	_size;


};

#endif /* *********************************************************** ARRAY_H */
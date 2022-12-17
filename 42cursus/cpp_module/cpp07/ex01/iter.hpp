/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:50:07 by balee             #+#    #+#             */
/*   Updated: 2022/12/17 15:50:08 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *addr, std::size_t len, void (*f)(const T &))
{
	for (size_t i = 0; i < len; i++)
		f(addr[i]);
}

template <typename T>
void	print(const T &target)
{
	std::cout << target << std::endl;
}

template<typename T>
void	increment(const T &target)
{
	const_cast<T &>(target)++;
}

#endif /* ************************************************************ ITER_H */
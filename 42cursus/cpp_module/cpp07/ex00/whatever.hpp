/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:10:45 by balee             #+#    #+#             */
/*   Updated: 2022/12/17 15:49:26 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T	tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T & min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	else 
		return (b);
}

template <typename T>
const T & max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	else 
		return (b);
}

template <typename T>
T & min(T &a, T &b)
{
	if (a < b)
		return (a);
	else 
		return (b);
}

template <typename T>
T & max(T &a, T &b)
{
	if (a > b)
		return (a);
	else 
		return (b);
}

#endif /* ******************************************************** WHATEVER_H */
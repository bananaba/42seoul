/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:13:35 by balee             #+#    #+#             */
/*   Updated: 2022/12/08 16:24:17 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point	d1 (b - a);
	Point	d2 (c - a);
	Point	p (point - a);
	Fixed	t1;
	Fixed	t2;

	if (a == b || b == c || c == a)
		return (false);
	if (d2.getY() != 0)
	{
		if (d1.getX() - d1.getY() * d2.getX() / d2.getY() == 0)
			return (false);
		t1 = (p.getX() - p.getY() * d2.getX() / d2.getY()) / (d1.getX() - d1.getY() * d2.getX() / d2.getY());
	}
	else
		t1 = p.getY() / d1.getY();
	if (d2.getX() != 0)
		t2 = (p.getX() - t1 * d1.getX()) / d2.getX();
	else
		t2 = (p.getY() - t1 * d1.getY()) / d2.getY();
	if (t1 + t2 < 1 && t1 > 0 && t1 < 1 && t2 > 0 && t2 < 1)
		return (true);
	return (false);
}

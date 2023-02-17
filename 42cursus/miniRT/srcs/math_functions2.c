/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:34:42 by snoh              #+#    #+#             */
/*   Updated: 2023/02/17 07:33:54 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	double_min(double a, double b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

double	double_max(double a, double b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	int_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	int_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

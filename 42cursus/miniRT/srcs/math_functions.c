/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:34:42 by snoh              #+#    #+#             */
/*   Updated: 2023/02/17 13:32:42 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	double_window(double min, double max, double x)
{
	if (x < min)
		return (min);
	else if (max < x)
		return (max);
	else
		return (x);
}

int	int_window(int min, int max, int x)
{
	if (x < min)
		return (min);
	else if (max < x)
		return (max);
	else
		return (x);
}

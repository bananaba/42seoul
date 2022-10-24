/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:29:58 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 13:30:11 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_atoi(const char *str)
{
	int			a;
	long long	r;
	long long	t;	
	int			s;

	s = 1;
	a = 0;
	r = 0;
	while ((9 <= str[a] && str[a] <= 13) || str[a] == 32)
		a++;
	if (str[a] == 45 || str[a] == 43)
		if (str[++a - 1] == 45)
			s *= -1;
	while ('0' <= str[a] && str[a] <= '9')
	{
		t = 10 * r + str[a++] - '0';
		if ((t - (str[a - 1] - '0')) / 10 == r)
			r = t;
		else
			if (s > 0)
				return (-1);
		else
			return (0);
	}
	return (s * r);
}

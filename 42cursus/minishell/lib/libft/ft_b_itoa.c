/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:38:51 by snoh              #+#    #+#             */
/*   Updated: 2022/10/28 00:38:40 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_b_itoa(char *buffer, int n)
{
	char		l[100];
	long		a;
	int			i;

	a = n;
	if (n < 0)
		a = -a;
	else if (n == 0)
	{
		ft_strlcpy(buffer, "0", 2);
		return ;
	}
	i = -1;
	l[99] = '\0';
	while (a > 0 && ((i++) || 1))
	{
		l[98 - i] = a % 10 + '0';
		a /= 10;
	}
	if (n < 0)
		l[98 - ++i] = 45;
	ft_strlcpy(buffer, &l[98 - i], ft_strlen(&l[98 - i]) + 1);
}

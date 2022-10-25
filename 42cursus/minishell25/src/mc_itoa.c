/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 06:34:04 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmc.h"

char	*mc_itoa(int n)
{
	char		l[100];
	long		a;
	int			i;

	a = n;
	if (n < 0)
		a = -a;
	else if (n == 0)
		return (mc_strdup("0"));
	i = -1;
	l[99] = '\0';
	while (a > 0 && ((i++) || 1))
	{
		l[98 - i] = a % 10 + '0';
		a /= 10;
	}
	if (n < 0)
		l[98 - ++i] = 45;
	return (mc_strdup(&l[98 - i]));
}

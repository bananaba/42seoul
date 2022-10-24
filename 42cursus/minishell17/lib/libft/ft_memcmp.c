/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:02:32 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 15:21:54 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*s1c;
	unsigned char	*s2c;

	a = 0;
	s1c = (unsigned char *) s1;
	s2c = (unsigned char *) s2;
	while (a < n)
	{
		if (s1c[a] - s2c[a])
			return ((s1c[a] - s2c[a]));
		a++;
	}
	return (0);
}

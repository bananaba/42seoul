/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:01:43 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 13:02:21 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	b;
	unsigned char	*sc;

	a = 0;
	b = (unsigned char) c;
	sc = (unsigned char *) s;
	while (a < n)
	{
		if (sc[a] == b)
			return ((void *) &s[a]);
		a++;
	}
	return (0);
}

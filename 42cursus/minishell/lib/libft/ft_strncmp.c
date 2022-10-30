/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:05:37 by snoh              #+#    #+#             */
/*   Updated: 2022/10/23 13:55:28 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			a;
	unsigned char	*s1c;
	unsigned char	*s2c;

	if (!n)
		return (0);
	a = 0;
	s1c = (unsigned char *) s1;
	s2c = (unsigned char *) s2;
	while ((a + 1 < n) && s1c[a])
	{
		if (s1c[a] - s2c[a])
			return (s1c[a] - s2c[a]);
		a++;
	}
	return (s1c[a] - s2c[a]);
}

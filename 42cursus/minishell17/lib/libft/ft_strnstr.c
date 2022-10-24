/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:06:01 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 13:06:25 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	if (0 == ft_strlen(needle))
		return ((char *) haystack);
	a = 0;
	while (haystack[a] && a < len)
	{
		b = 0;
		while (haystack[a + b] == needle[b] && haystack[a + b])
		{
			if ('\0' == needle[++b])
				return ((char *) haystack + a);
			if (a + b >= len)
				return (0);
		}
		a++;
	}
	return (0);
}

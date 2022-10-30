/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:30:28 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 16:19:55 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*subfunction for ft_strlcat*/
static long long	min(unsigned long long a, unsigned long long b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	m;
	size_t	n;
	size_t	r;

	m = 0;
	n = 0;
	r = ft_strlen(src);
	r += min(ft_strlen(dst), dstsize);
	m = ft_strlen(dst);
	while ((n + m + 1 < dstsize) && src[n])
	{
		dst[n + m] = src[n];
		n++;
	}
	dst[n + m] = '\0';
	return (r);
}

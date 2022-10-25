/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:01:18 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 14:50:23 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			a;
	unsigned char	*dstc;
	unsigned char	*srcc;

	if (dst != src)
	{
		a = -1;
		dstc = (unsigned char *) dst;
		srcc = (unsigned char *) src;
		if (dst > src)
		{
			while (++a < n)
				dstc[n - a - 1] = srcc[n - a - 1];
		}
		else
		{
			while (++a < n)
				dstc[a] = srcc[a];
		}
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:59:46 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 14:44:45 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			a;
	unsigned char	*dstc;
	unsigned char	*srcc;

	if (dst != src)
	{
		a = 0;
		dstc = (unsigned char *) dst;
		srcc = (unsigned char *) src;
		while (a < n)
		{
			dstc[a] = srcc[a];
			a++;
		}
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:03:55 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 13:04:05 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;

	n = 0;
	while ((n + 1 < dstsize) && src[n])
	{
		dst[n] = src[n];
		n++;
	}
	if (dstsize > 0)
		dst[n] = '\0';
	return (ft_strlen(src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:32:36 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:32:37 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	index;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	index = 0;
	if (size <= d_len)
		return (size + s_len);
	while (d_len + index < size - 1 && *(src + index) != 0 && size >= 1)
	{
		*(dest + d_len + index) = *(src + index);
		index++;
	}
	*(dest + d_len + index) = 0;
	return (d_len + s_len);
}

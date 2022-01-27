/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:32:40 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:32:43 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dest, char *src, size_t n)
{
	size_t	index;

	if (n >= 1)
	{
		index = 0;
		while (index < n - 1 && *(src + index) != '\0')
		{
			*(dest + index) = *(src + index);
			index++;
		}
		if (index < n)
			*(dest + index++) = '\0';
	}
	index = 0;
	while (src[index] != 0)
		index++;
	return (index);
}

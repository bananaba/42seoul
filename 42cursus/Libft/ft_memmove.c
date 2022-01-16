/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:31:56 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:31:57 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest <= src)
	{
		i = 0;
		while (i < n)
			*((char *)dest + i) = *((char *)src + i++);
	}
	else
	{
		i = n - 1;
		while (i >= 0)
			*((char *)dest + i) = *((char *)src + i--);
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:31:40 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:31:41 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	while (n-- > 0)
	{
		c1 = *(unsigned char *)str1;
		c2 = *(unsigned char *)str2;
		if (c1 != c2)
			return (c1 - c2);
		str1++;
		str2++;
	}
	return (0);
}

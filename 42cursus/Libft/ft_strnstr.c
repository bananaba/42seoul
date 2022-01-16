/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:32:59 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:33:01 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	index;

	while (*little != 0 && *big != 0 && len > 0)
	{
		index = 0;
		while (len - index > 0 && little[index] == big[index])
		{
			index++;
			if (little[index] == 0)
				return (big);
		}
		big++;
		len--;
	}
	return (0);
}

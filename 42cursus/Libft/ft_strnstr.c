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
	size_t	index;

	if (*little)
		return ((char *)big);
	while (*big != 0)
	{
		index = 0;
		while (len > index && little[index] == big[index] && big[index])
			index++;
		if (little[index] == 0)
			return ((char *)big);
		if (len == index)
			break ;
		big++;
		len--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:32:32 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:32:33 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(int size, char **strs, char *sep)
{
	int	temp;
	int	index1;
	int	index2;

	temp = 0;
	index1 = 0;
	if (size <= 0)
		return (0);
	while (index1 < size)
	{
		index2 = 0;
		while (strs[index1][index2] != 0)
		{
			temp++;
			index2++;
		}
		index1++;
	}
	index1 = 0;
	while (sep[index1] != 0)
		index1++;
	return (temp + index1 * (size - 1));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*temp;
	int		index1;
	int		index2;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(size, strs, sep) + 1));
	index1 = 0;
	while (index1 < size)
	{
		index2 = -1;
		while (strs[index1][++index2] != 0)
			*(temp++) = strs[index1][index2];
		if (index1 != size - 1)
		{
			index2 = -1;
			while (sep[++index2] != 0)
				*(temp++) = sep[index2];
		}
		index1++;
	}
	*temp = 0;
	return (temp - ft_strlen(size, strs, sep));
}

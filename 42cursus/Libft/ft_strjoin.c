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

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	index1;
	size_t	index2;

	if (!s1 && !s2)
		return (0);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp)
		return (0);
	index1 = -1;
	while (++index1 <= ft_strlen(s1))
		temp[index1] = s1[index1];
	index1--;
	index2 = -1;
	while (++index2 < ft_strlen(s2))
		temp[index1 + index2] = s2[index2];
	temp[index1 + index2] = 0;
	return (temp);
}

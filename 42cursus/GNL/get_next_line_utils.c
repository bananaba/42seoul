/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 04:26:26 by balee             #+#    #+#             */
/*   Updated: 2022/05/28 04:26:35 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		*(dest + index++) = '\0';
	}
	index = 0;
	while (src[index] != 0)
		index++;
	return (index);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*temp;
	int		len;

	len = ft_strlen(s1) + 1;
	temp = (char *)malloc(sizeof(char) * len);
	if (!temp)
		return (0);
	ft_strlcpy(temp, (char *)s1, len);
	return (temp);
}

char	*ft_strjoin(char **s1, char const *s2)
{
	char	*temp;
	size_t	index1;
	size_t	index2;

	if (!*s1 && !s2)
		return (0);
	else if (!*s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (*s1);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!temp)
		return (0);
	index1 = -1;
	while (++index1 <= ft_strlen(*s1))
		temp[index1] = s1[index1];
	index1--;
	index2 = -1;
	while (++index2 < ft_strlen(s2))
		temp[index1 + index2] = s2[index2];
	temp[index1 + index2] = 0;
	free(*s1);
	return (temp);
}

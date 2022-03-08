/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:32:19 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:32:20 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_count(char *str, char charset)
{
	int		count;
	char	*temp;

	count = 0;
	temp = str - 1;
	while (*str != 0)
	{
		if (charset == *str)
		{
			if (str - temp > 1)
				count++;
			temp = str;
		}
		str++;
	}
	if (str - temp > 1)
		count++;
	return (count);
}

int	char_count(char *str, char charset)
{
	int	index;

	index = -1;
	while (str[++index] != 0)
		if (charset == str[index])
			break ;
	return (index);
}

char	*rm_charset(char *str, char charset)
{
	while (charset == *str)
		str++;
	return (str);
}

void	malloc_free(char **output, int i)
{
	while (--i >= 0)
	{
		free(output[i]);
		output[i] = 0;
	}
	free(output);
	output = 0;
}

char	**ft_split(char *str, char charset)
{
	char	**output;
	char	*temp;
	int		index;

	if (!str)
		return (0);
	output = (char **)malloc(sizeof(char *) * (str_count(str, charset) + 1));
	if (output == 0)
		return (0);
	index = -1;
	temp = str;
	while (++index < str_count(str, charset))
	{
		temp = rm_charset(temp, charset);
		output[index] = (char *)malloc(1 * (char_count(temp, charset) + 1));
		if (output[index] == 0)
		{
			malloc_free(output, index);
			return (0);
		}
		ft_strlcpy(output[index], temp, char_count(temp, charset) + 1);
		temp += char_count(temp, charset) + 1;
	}
	output[index] = 0;
	return (output);
}

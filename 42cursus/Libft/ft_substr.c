/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:33:19 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:33:20 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	substr = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!substr)
		return (0);
	while (s[i] && i < start)
		i++;
	while (s[i] && len > 0)
	{
		substr[i - start] = s[i];
		i++;
		len--;
	}
	substr[i - start] = 0;
	return (substr);
}

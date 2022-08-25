/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:33:09 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:33:10 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*trim;
	int		len;

	if (!s1 || !set)
		return (0);
	start = (char *)s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = start - 1;
	while (*(++end))
		if (!ft_strchr(set, *end))
			len = end - start + 1;
	if (end == start)
		return (ft_strdup(""));
	trim = (char *)malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (0);
	trim[len] = 0;
	while (--len >= 0)
		trim[len] = start[len];
	return (trim);
}

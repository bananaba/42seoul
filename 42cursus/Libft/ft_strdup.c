/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:36:08 by balee             #+#    #+#             */
/*   Updated: 2022/01/28 17:36:09 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

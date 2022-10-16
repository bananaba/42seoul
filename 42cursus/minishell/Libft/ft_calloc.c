/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:27:47 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:27:49 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*temp;
	size_t	index;

	index = 0;
	temp = (char *)malloc(sizeof(char) * size * nmemb);
	if (!temp)
		return (0);
	while (index < size * nmemb)
		*(temp + index++) = 0;
	return (temp);
}

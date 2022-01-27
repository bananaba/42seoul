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
	void	*temp;
	size_t	index;

	index = 0;
	temp = malloc(size * nmemb);
	if (!temp)
		return (0);
	while (index < size * nmemb)
		*((char *)temp + index++) = 0;
	return (temp);
}

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

void	*calloc(size_t nmemb, size_t size)
{
	void	*temp;
	int		index;

	index = 0;
	temp = mallco(size * nmemb);
	if (!temp)
		return (0);
	while (index < size * nmemb)
		*((char *)temp + index) = 0;
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 06:34:49 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmc.h"

void	*mc_malloc(size_t size)
{
	void	*r;

	r = malloc(size);
	if (r)
	{
		memorybox("add", r);
		return (r);
	}
	else
	{
		exit_by_error(1);
		return (0);
	}
}

void	mc_free(void *pointer)
{
	if (memorybox("del", pointer))
	{
		free(pointer);
		return ;
	}
	else
	{
		return ;
	}
}

int	mc_freeint(void *pointer)
{
	if (memorybox("del", pointer))
	{
		free(pointer);
		return (0);
	}
	else
	{
		return (1);
	}
}

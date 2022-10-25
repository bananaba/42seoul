/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_memorybox2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 06:37:01 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmc.h"

void	*pop_nth_from_box(t_mem_box *box, int index)
{
	void	*r;

	if (index < 0 || box->size <= index)
		return (0);
	r = box->array[index];
	while (index < box->size)
	{
		box->array[index] = box->array[index + 1];
		index++;
	}
	box->size -= 1;
	return (r);
}

int	find_index(t_mem_box *box, void *arg)
{
	int	i;

	i = -1;
	while (++i < box->size)
	{
		if (box->array[i] == arg)
			return (i);
	}
	return (-1);
}

int	make_box_bigger(t_mem_box *box)
{
	int		i;
	void	**newarray;

	newarray = ft_calloc(sizeof(void *), box->capacity * 2);
	if (!newarray)
		return (1);
	i = -1;
	while (++i < box->size)
	{
		newarray[i] = box->array[i];
	}
	free(box->array);
	box->array = newarray;
	box->capacity *= 2;
	return (0);
}

int	is_box_full(t_mem_box *box)
{
	return (box->size == box->capacity);
}

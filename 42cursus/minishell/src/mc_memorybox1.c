/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_memorybox1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/27 22:40:54 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmc.h"

void	*memorybox(char *method, void *arg)
{
	static t_mem_box	box;

	if (method[0] == "init"[0])
		return (make_box(&box, 10000));
	else if (method[0] == "add"[0])
		return (add_arg_in_box(&box, arg));
	else if (method[0] == "del"[0])
		return (del_arg_in_box(&box, arg));
	else if (method[0] == "pop"[0])
		return (pop_nth_from_box(&box, 0));
	else if (method[3] == "dest"[3])
		return (dest_box(&box));
	return (0);
}

void	*make_box(t_mem_box *box, int capacity)
{
	box->array = ft_calloc(sizeof(void *), capacity + 1);
	if (!box->array)
		return (0);
	box->capacity = capacity;
	box->size = 0;
	return (box);
}

void	*add_arg_in_box(t_mem_box *box, void *arg)
{
	if (find_index(box, arg) != -1)
		return (0);
	if (is_box_full(box))
		if (make_box_bigger(box))
			exit_by_error(1);
	box->array[box->size++] = arg;
	return (box);
}

void	*del_arg_in_box(t_mem_box *box, void *arg)
{
	int	i;

	i = find_index(box, arg);
	if (i != -1)
		return (pop_nth_from_box(box, i));
	return (0);
}

void	*dest_box(t_mem_box *box)
{
	void	*p;

	p = pop_nth_from_box(box, box->size - 1);
	while (p)
	{
		free(p);
		pop_nth_from_box(box, box->size - 1);
	}
	free(box->array);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:55:24 by balee             #+#    #+#             */
/*   Updated: 2022/07/01 16:26:22 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
		*((char *)s + i++) = 0;
}

void	free_all(t_info *info)
{
	t_stack	*temp;
	t_stack	*next;

	temp = info->a_bottom;
	while (temp)
	{
		next = temp->right;
		ft_bzero(temp, sizeof(t_stack));
		free(temp);
		temp = next;
	}
	temp = info->b_bottom;
	while (temp)
	{
		next = temp->right;
		ft_bzero(temp, sizeof(t_stack));
		free(temp);
		temp = next;
	}
	ft_bzero(info, sizeof(t_info));
}

int	is_small(t_info *info, int pivot, int b)
{
	t_stack	*temp;

	temp = info->b_top;
	while (b-- > 0)
	{
		if (temp->data >= pivot)
			return (1);
		temp = temp->left;
	}
	return (0);
}

int	is_big(t_info *info, int pivot, int a)
{
	t_stack	*temp;

	temp = info->a_top;
	while (a-- > 0)
	{
		if (temp->data < pivot)
			return (1);
		temp = temp->left;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:55:24 by balee             #+#    #+#             */
/*   Updated: 2022/07/06 04:25:02 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_log(t_info *info, int input)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return ;
	ft_bzero(temp, sizeof(t_stack));
	if (info->log)
		info->log->right = temp;
	temp->left = info->log;
	temp->data = input;
	info->log = temp;
}

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
	temp = info->log;
	while (temp)
	{
		next = temp->left;
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

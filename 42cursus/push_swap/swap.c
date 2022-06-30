/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:47 by balee             #+#    #+#             */
/*   Updated: 2022/06/30 16:34:27 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	int	temp;

	if (!info->a_top || !info->a_top->left)
		return ;
	temp = info->a_top->data;
	info->a_top->data = info->a_top->left->data;
	info->a_top->left->data = temp;
}

void	sb(t_info *info)
{
	int	temp;

	if (!info->b_top || !info->b_top->left)
		return ;
	temp = info->b_top->data;
	info->b_top->data = info->b_top->left->data;
	info->b_top->left->data = temp;
}

void	do_sa(t_info *info)
{
	if (info->a_top && info->a_top->left)
	{
		sa(info);
		write(1, "sa\n", 3);
	}
}

void	do_sb(t_info *info)
{
	if (info->b_top && info->b_top->left)
	{
		sb(info);
		write(1, "sb\n", 3);
	}
}

void	ss(t_info *info)
{
	sa(info);
	sb(info);
}

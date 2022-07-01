/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:42 by balee             #+#    #+#             */
/*   Updated: 2022/06/30 16:36:00 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *info)
{
	if (!info->a_bottom || !info->a_bottom->right)
		return ;
	info->a_bottom->left = info->a_top;
	info->a_top->right = info->a_bottom;
	info->a_bottom = info->a_bottom->right;
	info->a_bottom->left = 0;
	info->a_top = info->a_top->right;
	info->a_top->right = 0;
}

void	rrb(t_info *info)
{
	if (!info->b_bottom || !info->b_bottom->right)
		return ;
	info->b_bottom->left = info->b_top;
	info->b_top->right = info->b_bottom;
	info->b_bottom = info->b_bottom->right;
	info->b_bottom->left = 0;
	info->b_top = info->b_top->right;
	info->b_top->right = 0;
}

void	do_rra(t_info *info)
{
	if (info->a_bottom && info->a_bottom->right)
	{
		rra(info);
		write(1, "rra\n", 4);
	}
}

void	do_rrb(t_info *info)
{
	if (info->b_bottom && info->b_bottom->right)
	{
		rrb(info);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_info *info)
{
	rra(info);
	rrb(info);
}

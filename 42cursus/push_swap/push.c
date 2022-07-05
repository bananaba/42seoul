/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:40 by balee             #+#    #+#             */
/*   Updated: 2022/07/05 23:59:46 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_info *info)
{
	t_stack	*temp;

	if (!info->b_top)
		return ;
	temp = info->b_top->left;
	info->b_top->left = info->a_top;
	if (!info->a_top)
		info->a_bottom = info->b_top;
	else
		info->a_top->right = info->b_top;
	info->a_top = info->b_top;
	info->b_top = temp;
	if (!info->b_top)
		info->b_bottom = 0;
	else
		info->b_top->right = 0;
	(info->a_factor)++;
	(info->b_factor)--;
}

void	do_pa(t_info *info)
{
	if (info->b_top)
	{
		pa(info);
		new_log(info, 7);
	}
}

void	pb(t_info *info)
{
	t_stack	*temp;

	if (!info->a_top)
		return ;
	temp = info->a_top->left;
	info->a_top->left = info->b_top;
	if (!info->b_top)
		info->b_bottom = info->a_top;
	else
		info->b_top->right = info->a_top;
	info->b_top = info->a_top;
	info->a_top = temp;
	if (!info->a_top)
		info->a_bottom = 0;
	else
		info->a_top->right = 0;
	(info->a_factor)--;
	(info->b_factor)++;
}

void	do_pb(t_info *info)
{
	if (info->a_top)
	{
		pb(info);
		new_log(info, 8);
	}
}

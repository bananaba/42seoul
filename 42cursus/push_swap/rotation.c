/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:44 by balee             #+#    #+#             */
/*   Updated: 2022/07/04 23:56:10 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	if (!info->a_top || !info->a_top->left)
		return ;
	info->a_top->right = info->a_bottom;
	info->a_bottom->left = info->a_top;
	info->a_top = info->a_top->left;
	info->a_top->right = 0;
	info->a_bottom = info->a_bottom->left;
	info->a_bottom->left = 0;
}

void	rb(t_info *info)
{
	if (!info->b_top || !info->b_top->left)
		return ;
	info->b_top->right = info->b_bottom;
	info->b_bottom->left = info->b_top;
	info->b_top = info->b_top->left;
	info->b_top->right = 0;
	info->b_bottom = info->b_bottom->left;
	info->b_bottom->left = 0;
}

void	do_ra(t_info *info)
{
	if (info->a_top && info->a_top->left)
	{
		ra(info);
		new_log(info, 9);
	}
}

void	do_rb(t_info *info)
{
	if (info->b_top && info->b_top->left)
	{
		rb(info);
		new_log(info, 10);
	}
}

void	rr(t_info *info)
{
	ra(info);
	rb(info);
}

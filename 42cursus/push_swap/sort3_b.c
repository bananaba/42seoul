/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 01:51:01 by balee             #+#    #+#             */
/*   Updated: 2022/07/06 03:05:59 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_util3(t_info *info)
{
	do_pa(info);
	do_ra(info);
	do_sb(info);
	do_pa(info);
	do_pa(info);
	do_rra(info);
}

void	sort_b_util2(t_info *info, int a, int b, int c)
{
	if (a < c && b > c)
	{
		do_rb(info);
		do_pa(info);
		do_pa(info);
		if (info->b_factor != 1)
			do_rrb(info);
		do_pa(info);
	}
	else if (a < b && b < c && info->b_factor == 3)
	{
		do_sb(info);
		do_rrb(info);
		do_pa(info);
		do_pa(info);
		do_pa(info);
	}
	else
		sort_b_util3(info);
}

void	sort_b_util1(t_info *info, int a, int b, int c)
{
	if (a < b && a > c)
	{
		do_sb(info);
		do_pa(info);
		do_pa(info);
		do_pa(info);
	}
	else if (a > b && a < c && info->b_factor == 3)
	{
		do_rrb(info);
		do_pa(info);
		do_pa(info);
		do_pa(info);
	}
	else if (a > b && a < c)
	{
		do_pa(info);
		do_ra(info);
		do_sb(info);
		do_pa(info);
		do_rra(info);
		do_pa(info);
	}
	else
		sort_b_util2(info, a, b, c);
}

void	sort3_b(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->b_top->data;
	b = info->b_top->left->data;
	c = info->b_top->left->left->data;
	if (a > b && b > c)
	{
		do_pa(info);
		do_pa(info);
		do_pa(info);
	}
	else if (a > c && b < c)
	{
		do_pa(info);
		do_sb(info);
		do_pa(info);
		do_pa(info);
	}
	else
		sort_b_util1(info, a, b, c);
}

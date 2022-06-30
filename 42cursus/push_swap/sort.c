/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:45 by balee             #+#    #+#             */
/*   Updated: 2022/06/30 19:59:23 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_info *info, int a)
{
	if (a <= 1)
		return ;
	else if (a == 2)
	{
		if (info->a_top->left->data < info->a_top->data)
			do_sa(info);
	}
	else if (a == 3)
		sort_a_util1(info);
	else if (a_is_sorted(info, a))
		sort(info, a, 0);
}

int	pivoting_a(t_info *info, int a)
{
	int	index;
	int	pivot;

	index = 0;
	pivot = info->a_top->data;
	do_pb(info);
	do_rb(info);
	while (++index < a)
	{
		if (is_big(info, pivot, a - 1))
			break ;
		if (info->a_top->data < pivot)
		{
			do_pb(info);
			a--;
			index--;
		}
		else
			do_ra(info);
	}
	while (--index > 0)
		do_rra(info);
	sort_a(info, a - 1);
	return (a);
}

void	sort_b(t_info *info, int b)
{
	if (b <= 1)
		return ;
	else if (b == 2)
	{
		if (info->b_top->left->data > info->b_top->data)
			do_sb(info);
	}
	else if (b == 3)
		sort_b_util1(info);
	else if (b_is_sorted(info, b))
		sort(info, 0, b);
}

int	pivoting_b(t_info *info, int b)
{
	int	index;
	int	pivot;

	index = 0;
	pivot = info->b_top->data;
	do_pa(info);
	do_ra(info);
	while (++index < b)
	{
		if (is_small(info, pivot, b - 1))
			break ;
		if (info->b_top->data > pivot)
		{
			do_pa(info);
			b--;
			index--;
		}
		else
			do_rb(info);
	}
	while (--index > 0)
		do_rrb(info);
	sort_b(info, b - 1);
	return (b);
}

void	sort(t_info *info, int a, int b)
{
	int	trans;

	if (a <= 3)
		sort_a(info, a);
	else
	{
		trans = a - pivoting_a(info, a);
		do_rrb(info);
		do_pa(info);
		sort_b(info, trans);
		while (trans-- > 0)
			do_pa(info);
	}
	if (b <= 3)
		sort_b(info, b);
	else
	{
		trans = b - pivoting_b(info, b);
		do_rra(info);
		do_pb(info);
		sort_a(info, trans);
		while (trans-- > 0)
			do_pb(info);
	}
}

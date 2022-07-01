/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:45 by balee             #+#    #+#             */
/*   Updated: 2022/07/01 17:41:55 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_info *info, int a, t_tree *root)
{
	if (a <= 1)
		return ;
	else if (a == 2)
	{
		if (info->a_top->left->data < info->a_top->data)
			do_sa(info);
	}
	else if (a_is_sorted(info, a))
	{
		if (a == 3)
			sort_a_util1(info);
		else if (a == 4)
			sort4_a(info);
		else if (a == 5)
			sort5_a(info);
		else if (a == 6)
			sort6_a(info);
		else
			sort(info, a, 0, root);
	}
}

int	pivoting_a(t_info *info, int a, t_tree *root)
{
	int	index;
	int	pivot;

	index = 0;
	pivot = root->data;
	while (is_big(info, pivot, a) && ++index <= a)
	{
		if (info->a_top->data < pivot)
		{
			do_pb(info);
			a--;
			index--;
		}
		else
			do_ra(info);
	}
	while (index-- > 0)
		do_rra(info);
	sort_a(info, a, root->right);
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
	else if (b_is_sorted(info, b))
		if (b == 3)
			sort_b_util1(info);
}

void	sort(t_info *info, int a, int b, t_tree *root)
{
	int	trans;

	if (a <= 5)
		sort_a(info, a, root);
	else
	{
		trans = a - pivoting_a(info, a, root);
		sort_b_to_a(info, trans, root->left);
	}
	if (b <= 3)
		sort_b(info, b);
}

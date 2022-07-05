/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:45 by balee             #+#    #+#             */
/*   Updated: 2022/07/06 04:51:36 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (info->a_factor != a && index-- > 0)
		do_rra(info);
	sort_a(info, a, root->right);
	return (a);
}

void	sort_a(t_info *info, int a, t_tree *root)
{
	int	trans;

	if (a <= 1 || !a_is_sorted(info, a))
		return ;
	else if (a == 2)
	{
		if (info->a_top->left->data < info->a_top->data)
			do_sa(info);
	}
	else if (a == 3)
		sort3_a(info);
	else if (a == 4)
		sort4_a(info);
	else if (a == 5)
		sort5_a(info);
	else
	{
		trans = a - pivoting_a(info, a, root);
		sort_b_to_a(info, trans, root->left);
	}
}

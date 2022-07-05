/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:41:33 by balee             #+#    #+#             */
/*   Updated: 2022/07/06 04:51:20 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivoting_b_to_a(t_info *info, int b, t_tree *root)
{
	int	index;
	int	pivot;

	index = 0;
	pivot = root->data;
	while (is_small(info, pivot, b) && ++index <= b)
	{
		if (info->b_top->data >= pivot)
		{
			do_pa(info);
			b--;
			index--;
		}
		else
			do_rb(info);
	}
	while (info->b_factor != b && index-- > 0)
		do_rrb(info);
	return (b);
}

void	sort_b_to_a(t_info *info, int trans, t_tree *root)
{
	int	b;

	b = trans;
	if (b <= 1)
		do_pa(info);
	else if (b == 2)
	{
		if (info->b_top->left->data > info->b_top->data)
			do_sb(info);
		do_pa(info);
		do_pa(info);
	}
	else if (b == 3)
		sort3_b(info);
	else if (b == 4)
		sort4_b(info);
	else if (b == 5)
		sort5_b(info);
	else
	{
		b = pivoting_b_to_a(info, trans, root);
		sort_a(info, trans - b, root->right);
		sort_b_to_a(info, b, root->left);
	}
}

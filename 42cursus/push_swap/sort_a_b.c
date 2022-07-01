/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:41:33 by balee             #+#    #+#             */
/*   Updated: 2022/07/01 17:44:08 by balee            ###   ########.fr       */
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
	while (index-- > 0)
		do_rrb(info);
	return (b);
}

void	sort_b_to_a(t_info *info, int trans, t_tree *root)
{
	int	b;

	b = trans;
	if (b <= 2)
	{
		sort_b(info, trans);
		while (trans-- > 0)
			do_pa(info);
	}
	else
	{
		b = pivoting_b_to_a(info, trans, root);
		sort_a(info, trans - b, root->right);
		sort_b_to_a(info, b, root->left);
	}
}

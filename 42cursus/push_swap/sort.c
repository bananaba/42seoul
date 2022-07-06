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

int	pivoting_a(t_info *info, int a, t_tree *root, int *c)
{
	int	index;

	index = 0;
	while (is_big(info, root->data, a) && ++index <= a)
	{
		if (info->a_top->data >= root->data)
			do_ra(info);
		else if (info->a_top->data >= root->left->data)
		{
			do_pb(info);
			a--;
			index--;
		}
		else
		{
			do_pb(info);
			if ((*c)++ != info->b_factor)
				do_rb(info);
			a--;
			index--;
		}
	}
	while (info->a_factor != a && index-- > 0)
		do_rra(info);
	return (a);
}

void	sort_c_to_a(t_info *info, int c, t_tree *root)
{
	int	index;

	index = 0;
	if (c != info->b_factor)
		while (index++ < c)
			do_rrb(info);
	sort_b_to_a(info, c, root);
}

void	sort_a(t_info *info, int a, t_tree *root)
{
	int	b;
	int	c;

	c = 0;
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
		b = a - pivoting_a(info, a, root, &c);
		sort_a(info, a - b, root->right);
		sort_b_to_a(info, b - c, root->left->right);
		sort_c_to_a(info, c, root->left->left);
	}
}

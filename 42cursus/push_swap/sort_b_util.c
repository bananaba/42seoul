/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:24:18 by balee             #+#    #+#             */
/*   Updated: 2022/06/30 19:58:11 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	b_is_sorted(t_info *info, int b)
{
	t_stack	*temp;
	int		data;

	data = info->b_top->data;
	temp = info->b_top->left;
	while (--b > 0)
	{
		if (data < temp->data)
			return (1);
		data = temp->data;
		temp = temp->left;
	}
	return (0);
}

void	sort_b_util3(t_info *info, int a, int b, int c)
{
	if (a < b && b < c && info->b_top->left->left->left)
	{
		do_sb(info);
		do_rb(info);
		do_sb(info);
		do_pa(info);
		do_rrb(info);
		do_pb(info);
	}
	else if (a < b && b < c)
	{
		do_sb(info);
		do_rrb(info);
	}
}

void	sort_b_util2(t_info *info, int a, int b, int c)
{
	if (a > b && a < c && info->b_top->left->left->left)
	{
		do_rb(info);
		do_sb(info);
		do_pa(info);
		do_rrb(info);
		do_pb(info);
	}
	else if (a > b && a < c)
		do_rrb(info);
	else if (a < c && b > c && info->b_top->left->left->left)
	{
		do_sb(info);
		do_rb(info);
		do_sb(info);
		do_rrb(info);
	}
	else if (a < c && b > c)
		do_rb(info);
	else
		sort_b_util3(info, a, b, c);
}

void	sort_b_util1(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->b_top->data;
	b = info->b_top->left->data;
	c = info->b_top->left->left->data;
	if (a > b && b > c)
		return ;
	else if (a > c && b < c && info->b_top->left->left->left)
	{
		do_pa(info);
		do_sb(info);
		do_pb(info);
	}
	else if (a > c && b < c)
	{
		do_rrb(info);
		do_sb(info);
	}
	else if (a < b && a > c)
		do_sb(info);
	else 
		sort_b_util2(info, a, b, c);
}
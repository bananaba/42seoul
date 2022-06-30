/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:24:18 by balee             #+#    #+#             */
/*   Updated: 2022/06/30 19:58:14 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_is_sorted(t_info *info, int a)
{
	t_stack	*temp;
	int		data;

	data = info->a_top->data;
	temp = info->a_top->left;
	while (--a > 0)
	{
		if (data > temp->data)
			return (1);
		data = temp->data;
		temp = temp->left;
	}
	return (0);
}

void	sort_a_util3(t_info *info, int a, int b, int c)
{
	if (a > b && b > c && info->a_top->left->left->left)
	{
		do_sa(info);
		do_ra(info);
		do_sa(info);
		do_pb(info);
		do_rra(info);
		do_pa(info);
	}
	else if (a > b && b > c)
	{
		do_sa(info);
		do_rra(info);
	}
}

void	sort_a_util2(t_info *info, int a, int b, int c)
{
	if (a < b && a > c && info->a_top->left->left->left)
	{
		do_ra(info);
		do_sa(info);
		do_pb(info);
		do_rra(info);
		do_pa(info);
	}
	else if (a < b && a > c)
		do_rra(info);
	else if (a > c && b < c && info->a_top->left->left->left)
	{
		do_sa(info);
		do_ra(info);
		do_sa(info);
		do_rra(info);
	}
	else if (a > c && b < c)
		do_ra(info);
	else
		sort_a_util3(info, a, b, c);
}

void	sort_a_util1(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->a_top->data;
	b = info->a_top->left->data;
	c = info->a_top->left->left->data;
	if (a < b && b < c)
		return ;
	else if (a < c && b > c && info->a_top->left->left->left)
	{
		do_pb(info);
		do_sa(info);
		do_pa(info);
	}
	else if (a < c && b > c)
	{
		do_rra(info);
		do_sa(info);
	}
	else if (a > b && a < c)
		do_sa(info);
	else 
		sort_a_util2(info, a, b, c);
}
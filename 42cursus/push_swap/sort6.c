/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:52:09 by balee             #+#    #+#             */
/*   Updated: 2022/07/01 16:52:11 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mid_util6(int num[6])
{
	int	index1;
	int	index2;
	int	status;

	index1 = -1;
	while (++index1 < 6)
	{
		index2 = -1;
		status = 0;
		while (++index2 < 6)
		{
			if (index1 != index2 && num[index1] > num[index2])
				status++;
			else if (index1 != index2)
				status--;
		}
		if (status == 1)
			break ;
	}
	return (num[index1]);
}

int	find_mid6(t_stack *temp)
{
	int	num[6];
	int	index;

	index = 0;
	while (index < 6)
	{
		num[index++] = temp->data;
		temp = temp->left;
	}
	return (find_mid_util6(num));
}

void	sort6_a(t_info *info)
{
	int	mid;
	int	index;
	int	check;

	mid = find_mid6(info->a_top);
	index = 0;
	check = 0;
	while (check != 3 && index++ < 6)
	{
		if (info->a_top->data >= mid)
			do_ra(info);
		else
		{
			do_pb(info);
			check++;
		}
	}
	index = index - 3;
	while (--index >= 0)
		if (info->a_top->left->left->left)
			do_rra(info);
	sort(info, 3, 3, 0);
	while (++index < 3)
		do_pa(info);
}

void	sort6_b(t_info *info)
{
	int	mid;
	int	index;
	int	check;

	mid = find_mid6(info->b_top);
	index = 0;
	check = 0;
	while (check != 3 && index++ < 6)
	{
		if (info->b_top->data < mid)
			do_rb(info);
		else
		{
			do_pa(info);
			check++;
		}
	}
	index = index - 3;
	while (--index >= 0)
		if (info->b_top->left->left->left)
			do_rrb(info);
	sort(info, 3, 3, 0);
	while (++index < 3)
		do_pb(info);
}

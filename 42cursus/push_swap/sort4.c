/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 03:13:29 by balee             #+#    #+#             */
/*   Updated: 2022/07/06 05:07:05 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mid_util4(int num[4])
{
	int	index1;
	int	index2;
	int	status;

	index1 = -1;
	while (++index1 < 4)
	{
		index2 = -1;
		status = 0;
		while (++index2 < 4)
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

int	find_mid4(t_stack *temp)
{
	int	num[4];
	int	index;

	index = 0;
	while (index < 4)
	{
		num[index++] = temp->data;
		temp = temp->left;
	}
	return (find_mid_util4(num));
}

void	sort4_a(t_info *info)
{
	int	mid;
	int	index;
	int	check;

	mid = find_mid4(info->a_top);
	index = 0;
	check = 0;
	while (check != 2 && index++ < 4)
	{
		if (info->a_top->data >= mid)
			do_ra(info);
		else
		{
			do_pb(info);
			check++;
		}
	}
	index = index - 2;
	if (info->a_top->left->left)
		while (--index >= 0)
			do_rra(info);
	sort_a(info, 2, 0);
	sort_b_to_a(info, 2, 0);
}

void	sort4_b(t_info *info)
{
	int	mid;
	int	index;
	int	check;

	mid = find_mid4(info->b_top);
	index = 0;
	check = 0;
	while (check != 2 && index++ < 4)
	{
		if (info->b_top->data < mid)
			do_rb(info);
		else
		{
			do_pa(info);
			check++;
		}
	}
	index = index - 2;
	if (info->b_top->left->left)
		while (--index >= 0)
			do_rrb(info);
	sort_a(info, 2, 0);
	sort_b_to_a(info, 2, 0);
}

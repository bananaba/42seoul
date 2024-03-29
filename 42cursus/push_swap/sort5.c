/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 00:17:07 by balee             #+#    #+#             */
/*   Updated: 2022/07/06 05:07:30 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mid_util5(int num[5])
{
	int	index1;
	int	index2;
	int	status;

	index1 = -1;
	while (++index1 < 5)
	{
		index2 = -1;
		status = 0;
		while (++index2 < 5)
		{
			if (index1 != index2 && num[index1] > num[index2])
				status++;
			else if (index1 != index2)
				status--;
		}
		if (status == 0)
			break ;
	}
	return (num[index1]);
}

int	find_mid5(t_stack *temp)
{
	int	num[5];
	int	index;

	index = 0;
	while (index < 5)
	{
		num[index++] = temp->data;
		temp = temp->left;
	}
	return (find_mid_util5(num));
}

void	sort5_a(t_info *info)
{
	int	mid;
	int	index;
	int	check;

	mid = find_mid5(info->a_top);
	index = 0;
	check = 0;
	while (check != 2 && index++ < 5)
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
	if (info->a_top->left->left->left)
		while (--index >= 0)
			do_rra(info);
	sort_a(info, 3, 0);
	sort_b_to_a(info, 2, 0);
}

void	sort5_b(t_info *info)
{
	int	mid;
	int	index;
	int	check;

	mid = find_mid5(info->b_top);
	index = 0;
	check = 0;
	while (check != 3 && index++ < 5)
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
	if (info->b_top->left->left)
		while (--index >= 0)
			do_rrb(info);
	sort_a(info, 3, 0);
	sort_b_to_a(info, 2, 0);
}

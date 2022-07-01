/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 03:13:29 by balee             #+#    #+#             */
/*   Updated: 2022/07/01 17:37:15 by balee            ###   ########.fr       */
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

void	sort4_util(t_info *info)
{
	if (info->a_top->data > info->a_top->left->data)
	{
		if (info->b_top->data < info->b_top->left->data)
		{
			sa(info);
			sb(info);
			write(1, "ss\n", 3);
		}
		else
			do_sa(info);
	}
	else if (info->b_top->data < info->b_top->left->data)
		do_sb(info);
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
	while (--index >= 0)
		if (info->a_top->left->left)
			do_rra(info);
	sort4_util(info);
	while (++index < 2)
		do_pa(info);
}

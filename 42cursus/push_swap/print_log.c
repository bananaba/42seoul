/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:52:56 by balee             #+#    #+#             */
/*   Updated: 2022/07/05 16:42:27 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_char(int data)
{
	if (data == 4)
		write(1, "sa\n", 3);
	else if (data == 5)
		write(1, "sb\n", 3);
	else if (data == 6)
		write(1, "ss\n", 3);
	else if (data == 7)
		write(1, "pa\n", 3);
	else if (data == 8)
		write(1, "pb\n", 3);
	else if (data == 9)
		write(1, "ra\n", 3);
	else if (data == 10)
		write(1, "rb\n", 3);
	else if (data == 16)
		write(1, "rr\n", 3);
	else if (data == 17)
		write(1, "rra\n", 4);
	else if (data == 18)
		write(1, "rrb\n", 4);
	else if (data == 24)
		write(1, "rrr\n", 4);
}

void	print_log(t_stack **log)
{
	if (*log)
		check_log(log);
	while (*log)
	{
		print_char((*log)->data);
		if (!(*log)->right)
			break ;
		*log = (*log)->right;
	}
}

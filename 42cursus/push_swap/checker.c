/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:05:45 by balee             #+#    #+#             */
/*   Updated: 2022/07/01 18:39:57 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sort(t_info *info)
{
	int		data;
	t_stack	*temp;

	if (info->b_top)
	{
		write(1, "KO\n", 3);
		return ;
	}
	else
	{
		data = info->a_bottom->data;
		temp = info->a_bottom->right;
		while (temp)
		{
			if (data <= temp->data)
			{
				write(1, "KO\n", 3);
				return ;
			}
			data = temp->data;
			temp = temp->right;
		}
		write(1, "OK\n", 3);
	}
}

int	do_exec(t_info *info, int status)
{
	if (status == 4)
		sa(info);
	else if (status == 5)
		sb(info);
	else if (status == 6)
		ss(info);
	else if (status == 7)
		pa(info);
	else if (status == 8)
		pb(info);
	else if (status == 9)
		ra(info);
	else if (status == 10)
		rb(info);
	else if (status == 16)
		rr(info);
	else if (status == 17)
		rra(info);
	else if (status == 18)
		rrb(info);
	else if (status == 24)
		rrr(info);
	else
		return (1);
	return (0);
}

int	checking(t_info *info)
{
	char	c;
	int		status;

	status = 0;
	while (read(0, &c, 1))
	{
		if (c == 'a')
			status += 1;
		else if (c == 'b')
			status += 2;
		else if (c == 's')
			status += 3;
		else if (c == 'p')
			status += 6;
		else if (c == 'r')
			status += 8;
		else if (c == '\n')
		{
			if (do_exec(info, status))
				return (1);
			status = 0;
		}
	}
	is_sort(info);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_tree	*root;
	t_info	info;
	int		index;
	int		status;

	root = 0;
	index = 0;
	if (argc == 1)
		return (0);
	ft_bzero(&info, sizeof(t_info));
	while (++index < argc)
	{
		status = keep_arg(&info, rm_whitespace(argv[index]), &root);
		if (status)
		{
			write(1, "Error\n", 6);
			break ;
		}
	}
	free_all_t_tree(root);
	if (!status && checking(&info))
		write(1, "KO\n", 3);
	free_all(&info);
	return (0);
}

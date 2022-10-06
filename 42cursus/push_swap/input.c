/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:32 by balee             #+#    #+#             */
/*   Updated: 2022/07/04 23:41:14 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_info *info, int n, t_tree **node)
{
	t_stack	*temp;
	int		status;

	status = add_input(node, n, info);
	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return (1);
	ft_bzero(temp, sizeof(t_stack));
	temp->data = n;
	if (!info->a_bottom)
	{
		info->a_bottom = temp;
		info->a_top = temp;
	}
	else if (status)
	{
		temp->right = info->a_bottom;
		info->a_bottom->left = temp;
		info->a_bottom = temp;
	}
	else
		free(temp);
	return (!status);
}

char	*rm_whitespace(char *argv)
{
	while ((*argv >= 9 && *argv <= 13) || *argv == ' ')
		argv++;
	return (argv);
}

int	keep_arg(t_info *info, char *argv, t_tree **node)
{
	long long	temp;
	int			s;

	if (!*argv)
		return (1);
	while (*argv)
	{
		temp = 0;
		s = 1;
		if ((*argv == '+' || *argv == '-')
			&& *(argv + 1) >= '0' && *(argv + 1) <= '9')
			if (*(argv++) == '-')
				s = -1;
		while (*argv >= '0' && *argv <= '9')
			temp = temp * 10 + *(argv++) - '0';
		if (!((*argv >= 9 && *argv <= 13) || *argv == ' ' || !*argv))
			return (1);
		else if (temp * s > MAX || temp * s < MIN || push(info, temp * s, node))
			return (1);
		argv = rm_whitespace(argv);
	}
	return (0);
}

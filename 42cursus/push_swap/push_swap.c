/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:36 by balee             #+#    #+#             */
/*   Updated: 2022/07/06 04:25:33 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			write(2, "Error\n", 6);
			break ;
		}
	}
	if (!status && a_is_sorted(&info, info.a_factor))
		sort_a(&info, info.a_factor, root);
	print_log(&(info.log));
	free_all_t_tree(root);
	free_all(&info);
	return (0);
}

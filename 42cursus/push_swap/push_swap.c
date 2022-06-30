/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:36 by balee             #+#    #+#             */
/*   Updated: 2022/06/30 16:55:44 by balee            ###   ########.fr       */
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
	ft_bzero(&info, sizeof(t_info));
	while (++index < argc)
	{
		status = keep_arg(&info, rm_whitespace(argv[index]), &root);
		if (status)
		{
			write(1, "Error\n", 6);
			free_all(&info);
		}
	}
	free_all_t_tree(root);
	sort(&info, info.a_factor, 0);
	free_all(&info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:25:14 by balee             #+#    #+#             */
/*   Updated: 2022/10/24 20:25:15 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **argv)
{
	if (argv[1] == NULL)
	{
		printf("exit\n");
		exit(errno);
	}
	else if (argv[2] == NULL)
	{
		printf("exit\n");
		exit(ft_atoi(argv[1]));
	}
	else
		ft_putstr_fd("Error: exit: too many arguments\n", 2);
}

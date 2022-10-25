/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:25:14 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 06:03:54 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	alpha_in(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (true);
		i++;
	}
	return (false);
}

void	ft_exit(char **argv)
{
	if (argv[1] == NULL)
	{
		printf("exit\n");
		exit_by_error(errno);
	}
	else if (alpha_in(argv[1]))
	{
		errno = 255;
		print_errno(errno, argv);
		exit_by_error(errno);
	}
	else if (argv[2] == NULL)
	{
		printf("exit\n");
		exit_by_error(ft_atoi(argv[1]));
	}
	else
		errno = -1;
}

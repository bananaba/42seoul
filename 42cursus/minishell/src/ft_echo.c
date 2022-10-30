/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:20 by balee             #+#    #+#             */
/*   Updated: 2022/10/28 03:08:46 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char *argv[], int **pipes)
{
	int	option_n;
	int	i;

	option_n = check_n(argv);
	i = option_n;
	while (argv[i] && argv[i][0])
	{
		if (i != option_n)
			write(pipes[1][1], " ", 1);
		write(pipes[1][1], argv[i], ft_strlen(argv[i]));
		i++;
	}
	if (!option_n)
		write(pipes[1][1], "\n", 1);
	return (errno);
}

int	check_n(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] && ft_strncmp(argv[i], "-n", 2) == 0)
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] != 'n')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

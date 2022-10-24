/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:20 by balee             #+#    #+#             */
/*   Updated: 2022/10/24 19:54:20 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_n(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] && ft_strncmp(argv[i], "-n", 2) == 0)
	{
		j = 2;
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

int	ft_echo(t_mp *mp, char *argv[], int **pipes)
{
	int	i;
	int	option;

	i = check_n(argv);
	if (i != 0)
		option = true;
	else
		option = false;
	while (argv[i])
	{
		if (i != 0)
			write(pipes[1][1], " ", 1);
		write(pipes[1][1], argv[i], ft_strlen(argv[i]));
	}
	if (option == false)
		write(pipes[1][1], "\n", 1);
	return (errno);
}

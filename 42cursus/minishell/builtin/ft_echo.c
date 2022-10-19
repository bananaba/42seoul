/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:20:27 by balee             #+#    #+#             */
/*   Updated: 2022/10/19 16:21:11 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_option(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
		return (1);
	while (argv[i])
	{
		j = 2;
		if (ft_strncmp(argv[i], "-n", 2) == 0)
			while (argv[i][j])
				if (argv[i][j++] != 'n')
					return (i);
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	option;

	i = check_option(argc, argv);
	if (i == 1)
		option = true;
	else
		option = false;
	while (i < argc)
	{
		if (i != 1)
			printf(" ");
		printf("%s", argv[i++]);
	}
	if (option == false)
		printf("\n");
	return (errno);
}

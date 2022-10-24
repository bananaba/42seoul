<<<<<<< HEAD
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
=======
#include "../includes/minishell.h"

int	check_n(int argc, char *argv[])
>>>>>>> b2e2fc83eaaabc95589be59b8de7883a22617cd1
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
<<<<<<< HEAD
		return (1);
	while (argv[i])
	{
		j = 2;
		if (ft_strncmp(argv[i], "-n", 2) == 0)
			while (argv[i][j])
				if (argv[i][j++] != 'n')
					return (i);
=======
		return (0);
	while (i < argc && ft_strncmp(argv[i], "-n", 2) == 0)
	{
		j = 2;
		while (argv[i][j])
		{
			if (argv[i][j] != 'n')
				return (i);
			j++;
		}
>>>>>>> b2e2fc83eaaabc95589be59b8de7883a22617cd1
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	option;

<<<<<<< HEAD
	i = check_option(argc, argv);
	if (i == 1)
=======
	i = check_n(argc, argv);
	if (i != 1)
>>>>>>> b2e2fc83eaaabc95589be59b8de7883a22617cd1
		option = true;
	else
		option = false;
	while (i < argc)
	{
		if (i != 1)
			printf(" ");
<<<<<<< HEAD
		printf("%s", argv[i++]);
=======
		printf("%s", argv[i]);
>>>>>>> b2e2fc83eaaabc95589be59b8de7883a22617cd1
	}
	if (option == false)
		printf("\n");
	return (errno);
}

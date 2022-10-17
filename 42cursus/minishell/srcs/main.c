/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:09:44 by balee             #+#    #+#             */
/*   Updated: 2022/10/17 13:14:24 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_myshell	myshell;
	int	n;
	char **temp;

	n = argc;
	temp = argv;
	init_minishell(&myshell, envp);
	read_cmd(&myshell);
	return (0);
}

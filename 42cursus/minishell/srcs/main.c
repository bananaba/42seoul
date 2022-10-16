/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:09:44 by balee             #+#    #+#             */
/*   Updated: 2022/10/16 22:12:00 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_minishell(t_myshell *myshell, char *envp[])
{
	set_input_mode(myshell);
	myshell->envp = envp;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_myshell	*myshell;

	signal_management();
	return (0);
}

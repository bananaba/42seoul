/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_1_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/25 20:38:03 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int initialize_signal();
static void	handlr(int sig);


int initialize(t_mp **mpp, int argc, char **argv, char **envp)
{
	t_mp	*mp;

	mp = ft_calloc(sizeof(struct s_minishell_program), 1);
	if (!mp)
		return(1);

	mp->initial_argv = argv;
	mp->initial_envp = envp;
	mp->error_flag = 0;
	splited_2dup_strlist(&mp->envp, envp);
	// 해야됨: 그리고 $? 추가해야함

	initialize_signal();
	// allocate and initialize mp structure
	// set signal handlr
	// get envp

	mp-> command = 0;
	*mpp = mp;
	return (0);
}

int	initialize_signal(void)
{
	ft_printf("server PID  : %i\n", getpid());
	signal(SIGINT, handlr);
	signal(SIGQUIT, handlr);
	return (0);
}

static void	handlr(int sig)
{
	int	i;

	i = -1;
	while (pid && pid[++i])
	{
		if (pid[i] > 0)
			kill(pid[i], sig);
	}
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		if (!pid)
			rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		ft_printf("\b\b");
		rl_on_new_line();
		if (!pid)
			rl_redisplay();
	}
}

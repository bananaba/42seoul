/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/02 16:11:56 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int initialize_signal();
static void	handlr(int sig, siginfo_t *siginfo, void *context);


int initialize(t_mp **mpp, int argc, char **argv, char **envp)
{
	t_mp	*mp;

	mp = ft_calloc(sizeof(struct s_minishell_program), 1);
	if (!mp)
		exit_by_error(1);

	mp->initial_argv = argv;
	mp->initial_envp = envp;
	mp->error_flag = 0;
	splited_2_strlist(&mp->envp, envp);
	// 해야됨: 그리고 $? 추가해야함

	initialize_signal();
	// allocate and initialize mp structure
	// set signal handlr
	// get envp

	mp-> command = ft_calloc(sizeof(t_c), 1);
	*mpp = mp;
	return (0);
}

int initialize_signal()
{
	struct sigaction	act;

	ft_printf("server PID  : %i\n", getpid());
	ft_bzero(&act, sizeof(act));
	act.sa_sigaction = &handlr;
	act.sa_flags = SA_SIGINFO;
	
	if (sigaction(SIGINT, &act, NULL))
		return (1);
	if (sigaction(SIGQUIT, &act, NULL))
		return (1);
	return (0);
}

static void	handlr(int sig, siginfo_t *siginfo, void *context)
{

	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();

	}
	else if (sig == SIGQUIT)
	{
		ft_printf("\b\b");
		rl_on_new_line();
		rl_redisplay();
	}


}

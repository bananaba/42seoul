/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_1_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/28 02:17:33 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			initialize_signal(void);
static void	handlr(int sig);

void	set_terminal_mode(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
}

void	init_envp_in_membox(t_mp *mp)
{
	t_list	*envp;
	char	*str;

	envp = mp->envp;
	while (envp)
	{
		str = envp->content;
		memorybox("add", str);
		memorybox("add", envp);
		envp = envp->next;
	}
}

int	initialize(t_mp **mpp, int argc, char **argv, char **envp)
{
	t_mp	*mp;

	mp = ft_calloc(sizeof(struct s_minishell_program), 1);
	if (!mp)
		return (1);
	mp->initial_argc = argc;
	mp->initial_argv = argv;
	mp->initial_envp = envp;
	mp->error_flag = 0;
	mp->pid = 0;
	splited_2dup_strlist(&mp->envp, envp);
	initialize_signal();
	memorybox("init", 0);
	memorybox("add", mp);
	exit_by_error(-100);
	set_terminal_mode();
	init_envp_in_membox(mp);
	mp->command = 0;
	up_shlvl(mp->envp);
	*mpp = mp;
	return (0);
}

int	initialize_signal(void)
{
	ft_printf("miniSHELL PID  : %i\n", getpid());
	signal(SIGINT, handlr);
	signal(SIGQUIT, handlr);
	return (0);
}

static void	handlr(int sig)
{
	if (sig == SIGINT)
	{
		if (g_recent_exit_code != -1)
		{
			rl_on_new_line();
			ft_printf("\n");
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	else if (sig == SIGQUIT)
	{
		if (g_recent_exit_code != -1)
		{
			rl_on_new_line();
			rl_redisplay();
		}
	}
}

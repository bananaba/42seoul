/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:04 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 06:53:51 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_proc(char **argv, char **envp, int **pipes)
{
	if (errno != EINVAL && errno != 0)
	{
		print_errno(errno, argv);
		exit(errno);
	}
	dup2(pipes[0][0], STDIN_FILENO);
	dup2(pipes[1][1], STDOUT_FILENO);
	execve(argv[0], argv, envp);
	exit(errno);
}

void	do_builtin(t_mp *mp, char **argv, int **pipes)
{
	errno = 0;
	if (ft_strncmp(argv[0], "cd", 3) == 0)
		ft_cd(mp, argv[1]);
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		ft_unset(mp, &argv[1]);
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		ft_export(mp, &argv[1], pipes);
	else if (ft_strncmp(argv[0], "pwd", 4) == 0)
		ft_pwd(mp, pipes);
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		ft_env(mp, pipes);
	else if (ft_strncmp(argv[0], "echo", 5) == 0)
		ft_echo(&argv[1], pipes);
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		ft_exit(argv);
	if (errno)
	{
		print_errno(errno, argv);
		errno = 1;
	}
	mp->recent_exit_code = errno;
}

pid_t	run_proc(t_mp *mp, t_e *excutable, int **pipes)
{
	char	**envp;
	char	**argv;
	pid_t	pid;

	if (mp->runnable->num_of_excutables == 1
		&& check_builtin(excutable->argv[0]))
	{
		do_builtin(mp, excutable->argv, pipes);
		return (0);
	}
	else
		pid = fork();
	if (pid == 0)
	{
		errno = 0;
		argv = set_argv(mp, excutable->argv);
		envp = set_envp(mp, argv[0]);
		if (check_builtin(argv[0]))
			do_builtin(mp, excutable->argv, pipes);
		else
			exec_proc(argv, envp, pipes);
		envp = mc_split_free(envp);
		exit(errno);
	}
	return (pid);
}

int	free_pipes(int **pipes, int i)
{
	close(pipes[i][0]);
	close(pipes[i][1]);
	mc_free(g_pid);
	g_pid = NULL;
	i = -1;
	while (pipes[++i])
		mc_free(pipes[i]);
	mc_free(pipes);
	return (errno);
}

int	run(t_mp *mp)
{
	int		i;
	int		status;
	int		**pipes;

	if (mp->error_flag != 0)
		return (mp->error_flag);
	pipes = init_pipe(mp->runnable);
	g_pid = mc_calloc(sizeof(pid_t), (mp->runnable->num_of_excutables + 1));
	i = -1;
	while (mp->runnable->excutables[++i] && mp->error_flag == 0)
	{
		errno = 0;
		set_lredirect(mp->runnable->excutables[i]->redirections, &pipes[i]);
		close(pipes[i][1]);
		if (mp->runnable->excutables[i]->argv)
			g_pid[i] = run_proc(mp, mp->runnable->excutables[i], &pipes[i]);
		close(pipes[i][0]);
		if (g_pid[i] > 0)
		{
			waitpid(g_pid[i], &status, 0);
			mp->recent_exit_code = WEXITSTATUS(status);
		}
		set_recent_exit_code(mp);
	}
	return (free_pipes(pipes, i));
}

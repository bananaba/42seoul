/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:02:57 by balee             #+#    #+#             */
/*   Updated: 2022/09/13 04:51:13 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(t_pipex *pipex, char **envp, int i, int cmd_num)
{
	if (i == 0)
		dup2(pipex->infile, STDIN_FILENO);
	else
		dup2(pipex->fd[i - 1][0], STDIN_FILENO);
	if (i == cmd_num)
		dup2(pipex->outfile, STDOUT_FILENO);
	else
		dup2(pipex->fd[i][1], STDOUT_FILENO);
	close_all(pipex);
	execve(pipex->cmd[i][0], pipex->cmd[i], envp);
	check_err(errno);
}

void	link_pipe(int cmd_num, t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->fd = (int **)malloc(sizeof(int *) * (cmd_num));
	check_err(errno);
	while (i < cmd_num - 1)
	{
		pipex->fd[i] = (int *)malloc(sizeof(int) * 2);
		check_err(errno);
		pipe(pipex->fd[i]);
		check_err(errno);
		i++;
	}
	pipex->fd[i] = NULL;
}

void	make_pipe(int cmd_num, char **envp, t_pipex *pipex)
{
	pid_t	pid;
	int		i;
	int		status;

	i = 0;
	link_pipe(cmd_num, pipex);
	while (i < cmd_num)
	{
		pid = fork();
		if (pid < 0)
			check_err(errno);
		else if (pid == 0)
			child_process(pipex, envp, i, cmd_num - 1);
		i++;
	}
}

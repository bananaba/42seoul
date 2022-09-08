/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:00:20 by balee             #+#    #+#             */
/*   Updated: 2022/08/25 18:00:20 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_all(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->fd[i] != NULL)
	{
		close(pipex->fd[i][0]);
		close(pipex->fd[i][1]);
		free(pipex->fd[i]);
		pipex->fd[i] = NULL;
		i++;
	}
	free(pipex->fd);
	pipex->fd = NULL;
}

void	free_all(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		free(ptr[i++]);
	free(ptr);
}

void	safe_exit(t_pipex *pipex)
{
	int	i;

	i = 0;
	close_all(pipex);
	free_all(pipex->path);
	while (pipex->cmd[i] != NULL)
		free_all(pipex->cmd[i++]);
	free(pipex->cmd);
}

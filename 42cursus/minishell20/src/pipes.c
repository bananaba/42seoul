/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:41 by balee             #+#    #+#             */
/*   Updated: 2022/10/25 17:10:49 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pipes(t_r *runnable, int **pipes)
{
	int	i;
	t_e	*ex;

	i = 0;
	while (i < runnable->num_of_excutables)
	{
		ex = runnable->excutables[i];
		if (i == 0 && is_ltoken(ex->redirections))
			dup2(STDIN_FILENO, pipes[i][0]);
		if (i + 1 == runnable->num_of_excutables
			&& is_rtoken(ex->redirections))
			dup2(STDOUT_FILENO, pipes[i + 1][1]);
		i++;
	}
}

int	**init_pipe(t_r *runnable)
{
	int	**pipes;
	int	i;

	pipes = (int **)malloc(sizeof(int *) * (runnable->num_of_excutables + 1));
	i = 0;
	while (i <= runnable->num_of_excutables)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		pipe(pipes[i]);
		i++;
	}
	set_pipes(runnable, pipes);
	return (pipes);
}

void	set_rredirect(t_list *rd, int **pipes)
{
	int		fd;
	char	*line;

	if (ft_strncmp(((t_token *)rd->content)->text, ">>", 2) == 0)
	{
		fd = open(((t_token *)rd->next->content)->text,
				O_CREAT | O_RDWR | O_APPEND, 0644);
		dup2(fd, pipes[1][1]);
	}
	else if (ft_strncmp(((t_token *)rd->content)->text, ">", 1) == 0)
	{
		fd = open(((t_token *)rd->next->content)->text,
				O_CREAT | O_RDWR | O_TRUNC, 0644);
		dup2(fd, pipes[1][1]);
	}
	if (rd->next->next)
		set_lredirect(rd->next->next, pipes);
}

void	set_lredirect(t_list *rd, int **pipes)
{
	int		fd;
	char	*line;

	if (ft_strncmp(((t_token *)rd->content)->text, "<<", 2) == 0)
	{
		while (1)
		{
			line = readline("> ");
			if (ft_strncmp(line, ((t_token *)rd->next->content)->text,
					ft_strlen(line)) == 0)
			{
				free(line);
				break ;
			}
			ft_putendl_fd(line, pipes[0][1]);
			free(line);
		}
	}
	else if (ft_strncmp(((t_token *)rd->content)->text, "<", 1) == 0)
	{
		fd = open(((t_token *)rd->next->content)->text, O_RDONLY);
		dup2(fd, pipes[0][0]);
	}
	set_rredirect(rd, pipes);
}

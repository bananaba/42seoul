#include "minishell.h"

int	**init_pipe(t_r *runnable)
{
	int	**pipes;
	int	i;

	pipes = (int **)malloc(sizeof(int) * (runnable->num_of_runnables + 1));
	i = 0;
	while (i <= runnable->num_of_runnables)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		pipes(pipes[i]);
		i++;
	}
	return (pipes);
}

void	set_redirect(t_list *rd, int **pipes)
{
	int		fd;
	char	*line;

	if (ft_strncmp(rd->content->text, ">>") == 0)
	{
		fd = open(rd->next->content->text, O_CREAT | O_RDWR | O_APPEND, 0644);
		dup2(fd, pipes[1][1]);
	}
	else if (ft_strncmp(rd->content->text, ">") == 0)
	{
		fd = open(rd->next->content->text, O_CREAT | O_RDWR | O_TRUNC, 0644);
		dup2(fd, pipes[1][1]);
	}
	else if (ft_strncmp(rd->content->text, "<") == 0)
	{
		fd = open(rd->next->content->text, O_RDONLY);
		dup2(fd, pipes[0][0]);
	}
	else if (ft_strncmp(rd->content->text, "<<") == 0)
	{
		while (1)
		{
			line = readline("> ");
			if (ft_strncmp(line, rd->next->content->text, ft_strlen(line)))
				break;
			ft_putendl_fd(line, pipes[0][0]);
		}
		dup2(fd, pipes[0][0]);
	}
	if (rd->next->next)
		set_redirect(rd, pipes);
}

void	set_pipes(t_r *runnable, int **pipes)
{
	int	i;
	t_e	*ex;

	i = 0;
	ex = runnable->excutables;
	while (i <= runnable->num_of_excutables)
	{
		if (ex->redirections)
			set_redirect(ex->redirections, pipes);
		if (i == 0 && is_ltoken(ex->redirections))
			dup2(STDIN_FILENO, pipes[i][0]);
		else if (i == runnable->num_of_excutables && is_rtoken(ex->redirectinos))
			dup2(STDOUT_FILENO, pipes[i + 1][0]);
		i++;
	}
}

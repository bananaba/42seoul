#include "../includes/pipex.h"

void	add_path(char **cmd, t_pipex *pipex)
{
	int		i;
	char	*temp;

	i = 0;
	while (pipex->path[i] != NULL)
	{
		temp = ft_strjoin(pipex->path[i], cmd[0]);
		if (access(temp, F_OK) == TRUE)
		{
			free(cmd[0]);
			cmd[0] = temp;
			return ;
		}
		free(temp);
		i++;
	}
}

void	set_cmd(t_pipex *pipex)
{
	int		i;

	i = 0;
	while (pipex->cmd[i] != NULL)
	{
		if (ft_strncmp(pipex->cmd[i][0], "/", 1) == TRUE
			|| ft_strncmp(pipex->cmd[i][0], "./", 2) == TRUE
			|| ft_strncmp(pipex->cmd[i][0], "../", 3) == TRUE)
			continue ;
		add_path(pipex->cmd[i], pipex);
		i++;
	}
}

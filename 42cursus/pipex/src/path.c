/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:00:15 by balee             #+#    #+#             */
/*   Updated: 2022/08/25 18:00:16 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**find_path(char **envp)
{
	int		i;
	char	**path;
	char	*temp;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == TRUE)
		{
			path = ft_split(&envp[i][5], ':');
			i = 0;
			while (path[i] != 0)
			{
				temp = path[i];
				path[i] = ft_strjoin(path[i], "/");
				free(temp);
				i++;
			}
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	parse(int argc, char **argv, char **envp, t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->cmd = (char ***)malloc(sizeof(char **) * (argc - 1));
	check_err(errno);
	while (i < argc - 2)
	{
		pipex->cmd[i] = ft_split(argv[i + 2], ' ');
		check_err(errno);
		i++;
	}
	pipex->cmd[i] = NULL;
	pipex->path = find_path(envp);
	check_err(errno);
}

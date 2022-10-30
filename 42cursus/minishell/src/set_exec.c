/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:46 by balee             #+#    #+#             */
/*   Updated: 2022/10/27 17:28:37 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**path_value(t_mp *mp)
{
	int		i;
	char	**path;
	char	*temp;
	t_list	*envp;

	envp = mp->envp;
	while (envp != NULL)
	{
		if (ft_strncmp(envp->content, "PATH=", 5) == 0)
		{
			path = mc_split(&envp->content[5], ':');
			i = 0;
			while (path[i] != 0)
			{
				temp = path[i];
				path[i] = mc_strjoin(path[i], "/");
				mc_free(temp);
				i++;
			}
			return (path);
		}
		envp = envp->next;
	}
	return (NULL);
}

char	*find_path(t_mp *mp, char *cmd)
{
	int			i;
	char		*temp;
	char		**path;
	struct stat	s;

	i = -1;
	if (stat(cmd, &s) == 0)
		return (ft_strdup(cmd));
	path = path_value(mp);
	while (path && path[++i] != NULL)
	{
		temp = ft_strjoin(path[i], cmd);
		if (stat(temp, &s) == 0)
			break ;
		mc_free(temp);
		temp = NULL;
	}
	path = mc_split_free(path);
	errno = 0;
	return (temp);
}

char	**set_argv(t_mp *mp, char **argv)
{
	char		*cmd;

	if (check_builtin(argv[0]))
		return (argv);
	cmd = find_path(mp, argv[0]);
	if (cmd == NULL)
		errno = 127;
	else
	{
		mc_free(argv[0]);
		argv[0] = cmd;
	}
	return (argv);
}

int	check_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "cd", 3) && ft_strncmp(cmd, "echo", 5)
		&& ft_strncmp(cmd, "pwd", 4) && ft_strncmp(cmd, "env", 4)
		&& ft_strncmp(cmd, "export", 7) && ft_strncmp(cmd, "unset", 6)
		&& ft_strncmp(cmd, "exit", 5))
		return (false);
	return (true);
}

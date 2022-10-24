#include "minishell.h"

char	**set_envp(t_mp *mp, char *cmd)
{
	char	**envp;
	t_list	*new;
	t_list	*last;

	new = ft_lstnew(ft_strjoin("_=", cmd));
	last = ft_lstlast(mp->envp);
	ft_lstadd_back(&mp->envp, new);
	envp = lst_to_arr(mp->envp);
	free(new->content);
	free(new);
	new = NULL;
	last->next = NULL;
	return (envp);
}

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
			path = ft_split(&envp->content[5], ':');
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

	i = 0;
	if (stat(cmd, &s) == 0)
		return (cmd);
	path = path_value(mp);
	while (path[i] != NULL)
	{
		temp = ft_strjoin(path[i], cmd);
		if (stat(temp, &s) == 0)
			break ;
		free(temp);
		temp = NULL;
		i++;
	}
	free_double_pointer(&path);
	errno = 0;
	return (temp);
}

char	**set_argv(t_mp *mp, char **argv)
{
	char	*cmd;

	cmd = find_path(mp, argv[0]);
	if (cmd == NULL)
		errno = 127;
	else
	{
		free(argv[0]);
		argv[0] = cmd;
	}
	return (argv);
}

int	check_builtin(char *cmd)
{
	int	len;

	len = ft_strlen(cmd);
	if (ft_strncmp(cmd, "cd", len) && ft_strncmp(cmd, "echo", len)
		&& ft_strncmp(cmd, "pwd", len) && ft_strncmp(cmd, "env", len)
		&& ft_strncmp(cmd, "export", len) && ft_strncmp(cmd, "unset", len)
		&& ft_strncmp(cmd, "exit", len))
		return (true);
	return (false);
}

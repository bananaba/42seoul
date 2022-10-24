#include "minishell.h"

void	free_double_pointer(char ***arr)
{
	int	i;

	i = 0;
	while (*arr[i])
	{
		free(*arr[i]);
		*arr[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
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

char	**lst_to_arr(t_list *lst)
{
	char	**arr;
	int		i;
	t_list	*temp;

	arr = (char **)malloc(sizeof(char *) * (ft_lstsize(lst)+ 1));
	i = 0;
	temp = lst;
	while (temp)
	{
		arr[i++] = ft_strdup(temp->content);
		temp->next;
	}
	arr[i] = NULL;
	return (arr);
}

char *find_value(t_mp *mp, char *target)
{
	char	*value;
	t_list	*envp;

	envp = mp->envp;
	value = NULL;
	while (envp != NULL)
	{
		if (ft_strncmp(envp, target, ft_strlen(target)) == 0)
			value = ft_strdup(&envp[ft_strlen(target)]);
		envp = envp->next;
	}
	return (value);
}

void	free_arg_env(char **argv, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

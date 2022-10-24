#include "minishell.h"

int	ft_pwd(t_mp *mp, int **pipes)
{
	char	*pwd;
	t_list	*envp;

	envp = mp->envp;
	while (envp)
	{
		if (ft_strncmp(envp->content, "PWD=", 4) == 0)
		{
			pwd = ft_strdup(&envp->content[4]);
			break ;
		}
		envp = envp->next;
	}
	ft_putendl_fd(pwd, pipes[1][1]);
	free(pwd);
	return (errno);
}

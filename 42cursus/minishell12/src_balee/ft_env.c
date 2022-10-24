#include "minishell.h"

int	ft_env(t_mp *mp, char **argv, int **pipes)
{
	t_list	*envp;

	envp = mp->envp;
	while (envp)
	{
		ft_putendl_fd(envp[i++], pipes[1][1]);
		envp = envp->next;
	}
	return (errno);
}

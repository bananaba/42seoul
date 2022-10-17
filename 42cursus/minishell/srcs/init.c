#include "../includes/minishell.h"

void	get_info(t_myshell *myshell, char *envp[])
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PWD=", 4) == 0)
			myshell->pwd = ft_strdup(&envp[i][4]);
		else if (ft_strncmp(envp[i], "OLDPWD=", 7) == 0)
			myshell->oldpwd = ft_strdup(&envp[i][7]);
		else if (ft_strncmp(envp[i], "HOME=", 5) == 0)
			myshell->home = ft_strdup(&envp[i][5]);
		i++;
	}
}

void	init_minishell(t_myshell *myshell, char *envp[])
{
	pid = 0;
	set_input_mode(myshell);
	get_info(myshell, envp);
	signal_management();
	myshell->envp = envp;
}

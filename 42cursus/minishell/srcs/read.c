#include "../includes/minishell.h"

char	*set_pwd(t_myshell *myshell)
{
	char *pwd;

	if (ft_strncmp(myshell->pwd, myshell->home, ft_strlen(myshell->home)) == 0)
		pwd = ft_strjoin("~", &myshell->pwd[ft_strlen(myshell->home)]);
	else
		pwd = ft_strdup(myshell->pwd);
	return (pwd);
}

void	read_cmd(t_myshell *myshell)
{
	char	*pwd;

	while (1)
	{
		pwd = set_pwd(myshell);
		printf("$ MINISHELL | %s", pwd);
		myshell->cmd = readline(" > ");
		if (myshell->cmd == NULL)
		{
			break ;
		}
		else if (myshell->cmd[0] == '\0')
		{
		}
		else
		{
			add_history(myshell->cmd);
		}
		free(pwd);
	}
}
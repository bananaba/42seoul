 #include "../includes/minishell.h"

char	*change_argv(char *envp[], char *nenvp[], char *shp[], char *str[])
{
	int		i;
	char	*cmd;
	char	*temp;

	temp = ft_strrchr(str, "$");
	cmd = ft_strjoin(temp + 1, "=");
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], cmd, ft_strlen(cmd)) == 0)
			;
		i++;
	}
	while (shp[i])
	{
		if (ft_strncmp(shp[i], cmd, ft_strlen(cmd)) == 0)
			;
		i++;
	}
	free(cmd);
	cmd = NULL;
	return (str);
}

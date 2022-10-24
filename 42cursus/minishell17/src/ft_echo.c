#include "minishell.h"

int	check_n(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc && ft_strncmp(argv[i], "-n", 2) == 0)
	{
		j = 2;
		while (argv[i][j])
		{
			if (argv[i][j] != 'n')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_echo(t_mp *mp, char *argv[], int **pipes)
{
	int	i;
	int	option;

	i = check_n(argv);
	if (i != 0)
		option = true;
	else
		option = false;
	while (argv[i])
	{
		if (i != 0)
			write(pipes[1][1], " ", 1);
		write(pipes[1][1], argv[i], ft_strlen(argv[i]));
	}
	if (option == false)
		write(pipes[1][1], "\n", 1);
	return (errno);
}

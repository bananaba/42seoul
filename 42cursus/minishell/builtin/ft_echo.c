#include "../includes/minishell.h"

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

int	main(int argc, char *argv[])
{
	int	i;
	int	option;

	i = check_n(argc, argv);
	if (i != 1)
		option = true;
	else
		option = false;
	while (i < argc)
	{
		if (i != 1)
			printf(" ");
		printf("%s", argv[i]);
	}
	if (option == false)
		printf("\n");
	return (errno);
}

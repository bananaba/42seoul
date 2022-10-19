#include "../includes/minishell.h"

int	main(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd != NULL)
	{
		printf("%s\n", pwd);
		free(pwd);
		pwd = NULL;
	}
	return (errno);
}

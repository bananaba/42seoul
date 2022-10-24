# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include <term.h>
# include <stdbool.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <string.h>
/*
int main(int argc, char *argv[])
{
	char *dir;

	if (argc == 1)
		dir = strdup("~");
	else
		dir = strdup(argv[1]);
	chdir(dir);
	free(dir);
	printf("%s\n", getcwd(NULL, 0));
	return (0);
}*/

int	main(int argc, char *argv[], char *envp[])
{
	int	i = 0;

	while (envp[i])
		printf("%s\n", envp[i++]);
	return (errno);
}

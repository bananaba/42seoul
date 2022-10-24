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


int main(int argc, char **arv, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
		printf("%s\n", envp[i++]);
	return 0;
}
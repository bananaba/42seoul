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


int main(int argc, char **arvg, char **envp)
{
	char *str[2];
	
	str[0] = strdup("../minishell17/minishell");
	str[1] = 0;
	execve("../minishell17/minishell", str, envp);
	return 0;
}
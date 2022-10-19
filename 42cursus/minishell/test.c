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

void	process(char *envp[])
{
	char	*cmd[3];
	char	*c;

	cmd[0] = strdup("/Users/balee/42/42cursus/minishell/echo");
//	cmd[0] = strdup("/bin/echo");
	cmd[1] = strdup("a*");
	cmd[2] = NULL;
	execve(cmd[0], cmd, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;

//	for (int i = 0; envp[i]; i++)
//		printf("%s\n", envp[i]);
//	printf("A = $A\n");
	pid = fork();
	if (pid == 0)
		process(envp);
	else
		wait(NULL);
//	printf("%s", 12311231);
	return (0);
}

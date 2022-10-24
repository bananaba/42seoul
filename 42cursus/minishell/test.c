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

void	child_process()
{
	exit(4);
}

int main()
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
		child_process();
	else
		waitpid(pid, &status, 0);
	printf("%d\n", WEXITSTATUS(status));
}
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include <term.h>
# include <stdbool.h>

pid_t	pid;

void	signal_handler(int signum)
{
	int	status;

	if (signum == SIGINT)
	{
		if (waitpid(0, NULL, WNOHANG) == 0)
			exit(0);
		else
			kill(pid, SIGINT);
	}
	else if (signum == SIGQUIT)
	{
		if (waitpid(0, &status, WNOHANG) == 0 || WIFEXITED(status))
			exit(0);
		else
			kill(pid, SIGQUIT);
	}
}

void	signal_management(void)
{
//	signal(SIGINT, signal_handler_parent);
	signal(SIGQUIT, signal_handler);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid = fork();
	struct termios org;
	struct termios new;

//	for (int i = 0; envp[i]; i++)
//		printf("%s\n", envp[i]);
	if (pid == 0)
	{
/*		while (1)
		{
			printf("child\n");
			usleep(1000000);
		}*/
		exit(0);
	}
	else
	{
		signal_management();
		write(0, "1234", 4);
		write(0, "\b \b", 3);
		usleep(1000000);
	}
}
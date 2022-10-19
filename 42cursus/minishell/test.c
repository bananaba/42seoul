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
#include <string.h>

pid_t	pid = 0;
/*
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
		if (waitpid(0, &status, WNOHANG) != 0)
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
*/

int	main(int argc, char *argv[], char *envp[])
{
	pid = fork();
	int		status;
//	char	str[] = "asd";
//	char	*cmd;
//	struct termios org;
//	struct termios new;
//	signal_management();

//	for (int i = 0; envp[i]; i++)
//		printf("%s\n", envp[i]);
//	printf("%d\n", waitpid(0, &status, WNOHANG));
//	pid = fork();
	if (pid == 0)
	{
		char *cmd[3];
		cmd[0] = strdup("/Users/balee/42/42cursus/minishell/ft_cd");
		cmd[1] = strdup("..");
		cmd[2] = NULL;
		printf("%s\n", getcwd(NULL, 0));
		execve(cmd[0], cmd, envp);
//		while (1)
//		{
//			printf("child\n");
//			usleep(1000000);
//		}
//		exit(0);
	}
	else
	{
		waitpid(0, NULL, 0);
		printf("%s\n", getcwd(NULL, 0));	
//		usleep(100000);
//		printf("%d\n", waitpid(0, &status, WNOHANG));
//		printf("%d\n", WIFEXITED(status));
//		printf("%s", str);
//		cmd = readline("> ");
//		if (rl_on_new_line() == -1)
//			;
//		rl_replace_line("", 1);
//		rl_redisplay();
//		printf("%d\n", *cmd);
//		while (1)
//		{
//			printf("parent\n");
//			usleep(1000000);
//		}
	}
}
#include "../includes/minishell.h"

void	signal_handler(int signum)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (pid && pid[i])
	{
		if (waitpid(pid[i], NULL, WNOHANG) == 0)
		{
			kill(pid[i], signum);
			status = 1;
		}
		i++;
	}
	if (status == 0 && signum == SIGINT)
	{
		if (rl_on_new_line() == -1)
			;
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	signal_management(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

#include "../includes/minishell.h"

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{

	}
	else if (signum == SIGQUIT)
	{}
}

void	signal_management(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

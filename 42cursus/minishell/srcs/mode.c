#include "../includes/minishell.h"

void	set_input_mode(t_myshell *myshell)
{
	tcgetattr(STDIN_FILENO, &myshell->org);
	tcgetattr(STDIN_FILENO, &myshell->new);
	myshell->new.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &myshell->new);
}

void	reset_input_mode(t_myshell *myshell)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &myshell->org);
}

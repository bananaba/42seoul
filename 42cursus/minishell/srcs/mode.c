#include "../includes/minishell.h"

void	set_input_mode(t_myshell *myshell)
{
	tcgetattr(STDIN_FILENO, &myshell->org);
	tcgetattr(STDIN_FILENO, &myshell->new);
	myshell->new.c_lflag &= ~(ICANON | ECHO);	
	myshell->new.c_cc[VMIN] = 1;
	myshell->new.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &myshell->new);
}

void	reset_input_mode(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &myshell->org);
}

#ifndef		PIPEX_H
# define	PIPEX_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	<stdio.h>
# include	<errno.h>
# include	"../Libft/libft.h"

# define	TRUE	0
# define	FAIL	-1

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		**fd;
	char	***cmd;
	char	**path;
}	t_pipex;

void	check_err(int err);
//path.c
void	parse(int argc, char **argv, char **envp, t_pipex *pipex);
char	**find_path(char **envp);
//cmd.c
void	add_path(char **cmd, t_pipex *pipex);
void	set_cmd(t_pipex *pipex);

void	close_all(t_pipex *pipex);

#endif
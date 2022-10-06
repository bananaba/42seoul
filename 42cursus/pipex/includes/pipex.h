/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:59:29 by balee             #+#    #+#             */
/*   Updated: 2022/08/25 18:04:25 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "../Libft/libft.h"

# define TRUE	0
# define FAIL	-1

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		**fd;
	char	***cmd;
	char	**path;
}	t_pipex;

//main.c
void	check_err(int err);
//path.c
void	parse(int argc, char **argv, char **envp, t_pipex *pipex);
char	**find_path(char **envp);
//cmd.c
void	add_path(char **cmd, t_pipex *pipex);
void	set_cmd(t_pipex *pipex);
//exit.c
void	close_all(t_pipex *pipex);
void	free_all(char **ptr);
void	safe_exit(t_pipex *pipex);
//pipe.c
void	make_pipe(int cmd_num, char **envp, t_pipex *pipex);
void	link_pipe(int cmd_num, t_pipex *pipex);
void	child_process(t_pipex *pipex, char **envp, int i, int cmd_num);

#endif
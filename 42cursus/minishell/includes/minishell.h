/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:03:27 by balee             #+#    #+#             */
/*   Updated: 2022/10/17 14:20:40 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
# include "../Libft/libft.h"

pid_t	*pid;

typedef struct s_myshell
{
	char			**envp;
	char			*cmd;
	char			*pwd;
	char			*oldpwd;
	char			*home;
	struct termios	org;
	struct termios	new;
}	t_myshell;
//init.c
void	init_minishell(t_myshell *myshell, char *envp[]);
void	get_info(t_myshell *myshell, char *envp[]);
//signal.c
void	signal_management(void);
void	signal_handler(int signum);
//mode.c
void	set_input_mode(t_myshell *myshell);
void	reset_input_mode(t_myshell *myshell);
//read.c
void	read_cmd(t_myshell *myshell);
char	*set_pwd(t_myshell *myshell);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:03:27 by balee             #+#    #+#             */
/*   Updated: 2022/10/16 22:10:59 by balee            ###   ########.fr       */
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
# include "../Libft/libft.h"

typedef struct s_myshell
{
	char			**envp;
	pid_t			pid;
	struct termios	org;
	struct termios	new;
}	t_myshell;
//signal.c
void	signal_management(void);
void	signal_handler(int signum);
//mode.c
void	set_input_mode(t_myshell *myshell);

#endif

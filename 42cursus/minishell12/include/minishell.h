/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:42:31 by snoh              #+#    #+#             */
/*   Updated: 2022/10/03 18:24:21 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libftprintf.h"
# include "collector.h"
# include <limits.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

// The smallest unit in which a process runs
// matched with 1 process
typedef struct s_excutable
{

	char				*text;

	//temp
	char				*excutable_path;
	char				*redirections;

//	t_list				*path_list;
//	t_list				*redirection_list;

	char				**argv;//do not free
	t_list				**envp;//do not free


	//struct s_excutable	*input_pipe_from;
	//struct s_excutable	*output_pipe_to;

	int					num_of_input_redirects;
	int					num_of_output_redirects;

	// full path
	int					input_redirect_flag;
	char				**input_redirect;
	//int				input_redirect_fds[];
	
	int					output_redirect_flag;
	char				**output_redirect;
	//int				outputt_redirect_fds[];


	int					state;
}t_e;

// The smallest unit in which an instruction is executed
typedef struct s_runnable
{
	// "part of the command" that executed on this structure
	char				*text;

	int					num_of_excutables;
	struct s_excutable	**excutables;

	int					state;
	//100 : 파싱 중 메모리할당 안됨


	struct s_memory_box	mbox;

}t_r;

// Command entered by the user
typedef struct s_command
{
	// The smallest unit in which an instruction is executed
	char				*text;

	int					num_of_runnables;
	struct s_runnable	**runnables;

	//something			*runnable_structure : for bonus
	//int				run_state;

	int					state;

}t_c;

typedef struct s_minishell_program
{

// initial value
	int					initial_argc;
	char				**initial_argv;
	char				**initial_envp;

// environment variables for shell
	t_list				*envp;

// for minishells
	char				pwd[10000];

	struct s_command	*command;

	struct s_memory_box	mbox;

	int					recent_exit_code;

	int					error_flag;


}t_mp;




/*initialize*/
int		prompt(t_mp *mp);
int 	initialize(t_mp **mp, int argc, char **argv, char ** envp);
void	parse(t_mp *mp, t_r *runnable);
/*Main : push_Swap & checker*/
void	exit_by_error(int i);

/*Check_input*/
int		*check_input(int argc, char **argv);

/* for parsing*/
void 	excutable_tokenize(char *cmd, char * redirection, char * excutable);


/*assets*/
char	**strlist_2_splited(t_list **list);
char	**strlist_2_splited_fast(t_list **list);

int		splited_2_strlist(t_list **list, char **splited);

/* const and dest */
void *destruct_excutable(t_e *excutable);
void *destruct_runnable(t_r *runnable);
void *destruct_command(t_c *command);
void *destruct_minishell_program(t_mp *minishell_program);


void *ft_split_free(char **splited);
char *ft_split_join(char **splited);

void skip_quote(char *cmd, int *r);
void skip_space(char *str, int *i);


int	int_min(int a, int b);
int	int_max(int a, int b);

int variable_expansion(t_mp *mp, t_list *list);
char *variable_expansion_str(char *str, t_list *envp);
char *find_and_get_envp(char * str, int *index, t_list *envp);

int path_list_interpret(t_e *excutable, t_list *path_list);

int run(t_mp *mp, t_r *runnable);

void print_strlist(t_list *lst, char * name);
void print_splited(char **splited, char *name);
void print_excutable(t_e *excutable, char *name);
void print_runnable(t_r *runnable, char* name);





#endif	
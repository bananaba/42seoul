/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:42:31 by snoh              #+#    #+#             */
/*   Updated: 2022/10/24 02:02:25 by balee            ###   ########.fr       */
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
# define DEBUG 1


// The smallest unit in which a process runs
// matched with 1 process
typedef struct s_excutable
{
	char				**argv;
	t_list				*envp;//do not free
	t_list				*redirections;

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

/* 이건 보너스 할 떄까지 봉인
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
*/
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

	//struct s_command	*command;

	char				*command;

	//t_list 				token_start;

	struct s_runnable	*runnable;

	struct s_memory_box	mbox;

	int					recent_exit_code;

	int					error_flag;


}t_mp;



typedef struct s_token
{
	char	type;
	// pipe[0]
	// text[0]
	// quote[0]
	// double_quote[0]
	// redirection[0]
	// ledirection[0]
	// space[0]
	char	*text;
}	t_token;


//n_1.c
//tokenize()
void destroy_token(t_token *token);
t_token *new_token(char atype, char *atext);
void print_token(t_token *token, char *name ,int tabs);
int tokenize(char *text, t_list** token_start);
static t_list *label2token(char *text, char *labels);
static int connect_token(t_list **token_start, t_list *token_node);
static t_list *make_token_here(char *text, char *labels, int i);
static int check_label(char *labels);
char*	label_text(char *text);
static void mark_quote(char *text, char *labels, int *idx, int len);
static void mark_not_quote(char *text, char *labels, int i);
static int check_token(t_list *token_start);
void print_token_list(t_list *token_start, char *list_name);


//n_2.c
//variable_expansion()
int			variable_expansion(t_list *token_start, t_list *envp);
int			variable_expansion_token(t_token *text_token, t_list *envp);
void		expande_str(char *buffer, char *str, t_list *envp);
int			expanded_lenght_of_str(char *str, t_list *envp);
char		*get_envp(char *str, t_list *envp);
static int	ft_varlen(char *str);


/*initialize*/
int 	initialize(t_mp **mp, int argc, char **argv, char ** envp);

/*main*/
int		prompt(t_mp *mp);
void 	parse(t_mp *mp);



/*assets*/
char	**strlist_2_splited(t_list **list);
char	**strlist_2_splited_fast(t_list **list);

int		splited_2_strlist(t_list **list, char **splited);



/* const and dest */
void *destruct_excutable(t_e *excutable);
void *destruct_runnable(t_r *runnable);
//void *destruct_command(t_c *command);
void *destruct_minishell_program(t_mp *minishell_program);

void *ft_split_free(char **splited);
char *ft_split_join(char **splited);

int	int_min(int a, int b);
int	int_max(int a, int b);

void print_strlist(t_list *lst, char * name);
void print_splited(char **splited, char *name);
//void print_excutable(t_e *excutable, char *name);
//void print_runnable(t_r *runnable, char* name);

int run(t_mp *mp);
void	ft_cd(t_mp *mp, char *dir);
void	free_double_pointer(char ***arr);
int	check_builtin(char *cmd);
char	**lst_to_arr(t_list *lst);
char *find_value(t_mp *mp, char *target);
void	free_arg_env(char **argv, char **envp);
int	ft_echo(t_mp *mp, char *argv[], int **pipes);
int	ft_env(t_mp *mp, char **argv, int **pipes);
int	ft_pwd(t_mp *mp, char **argv, int **pipes);
int	ft_export(t_mp *mp, char **argv, int **pipes);
int	ft_unset(t_mp *mp, char *target);
int	is_ltoken(t_list *rd);
int	is_rtoken(t_list *rd);
int	**init_pipe(t_r *runnable);
void	set_pipes(t_r *runnable, int **pipes);
char	**path_value(t_mp *mp);
char	**set_argv(t_mp *mp, char **argv);

#endif	
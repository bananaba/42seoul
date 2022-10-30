/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:42:31 by snoh              #+#    #+#             */
/*   Updated: 2022/10/28 03:10:56 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libftprintf.h"
# include "collector.h"
# include "libmc.h"
# include <limits.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <term.h>
# define DEBUG 0
# define DEBUG1 0
# define DEBUG2 1

typedef struct s_excutable
{
	char		**argv;
	t_list		*envp;
	t_list		*redirections;
	int			state;
}	t_e;

typedef struct s_runnable
{
	char				*text;

	int					num_of_excutables;
	struct s_excutable	**excutables;

	int					state;
	struct s_memory_box	mbox;
}	t_r;

typedef struct s_minishell_program
{
	int					initial_argc;
	char				**initial_argv;
	char				**initial_envp;
	t_list				*envp;
	char				pwd[10000];
	char				*command;
	struct s_runnable	*runnable;
	struct s_memory_box	mbox;
	pid_t				*pid;
	int					error_flag;
}	t_mp;

typedef struct s_token
{
	char	type;
	char	*text;
}	t_token;

int				g_recent_exit_code;

int				divide_text_in_token(t_list *token_start);

//n_1.c
void			destroy_token(t_token *token);
t_token			*new_token(char atype, char *atext);
void			print_token(t_token *token, char *name, int tabs);
int				tokenize(char *text, t_list **token_start);
char			*label_text(char *text);
void			print_token_list(t_list *token_start, char *list_name);

//n_2.c
int				variable_expansion(t_list *token_start, t_list *envp);
int				variable_expansion_token(t_token *text_token, t_list *envp);
void			expande_str(char *buffer, char *str, t_list *envp);
int				expanded_lenght_of_str(char *str, t_list *envp);
char			*get_envp(char *str, t_list *envp);

//n_3.c
int				remove_quote(t_list *token_start);
int				remove_quote_token(t_token *quote_token);

//n_4.c
int				convert_to_runnable(t_mp *mp, t_list **token_start);

/*initialize*/
int				initialize(t_mp **mp, int argc, char **argv, char **envp);

/*main*/
int				prompt(t_mp *mp);
void			parse(t_mp *mp);

/*exit by error*/
void			exit_by_error(int code);

/*assets*/
char			**strlist_2_splited(t_list **list);
char			**strlist_2_splited_fast(t_list **list);

void			**linkedlist_2_array(t_list **lst);

int				splited_2_strlist(t_list **list, char **splited);
int				splited_2dup_strlist(t_list **list, char **splited);
void			do_nothing(void *p);

int				ft_is_assign(char *str);

/* const and dest */
void			*destruct_excutable(t_e *excutable);
void			*destruct_runnable(t_r *runnable);
void			*destruct_minishell_program(t_mp *minishell_program);

t_e				*new_excutable(t_list *envp);
t_r				*new_runnable(void);
t_r				*new_runnable_with_size(int size);

void			*ft_split_free(char **splited);
char			*ft_split_join(char **splited);

int				int_min(int a, int b);
int				int_max(int a, int b);

void			print_strlist(t_list *lst, char *name);
void			print_splited(char **splited, char *name);
void			print_excutable(t_e *excutable, char *name);

//exec.c
int				run(t_mp *mp);
pid_t			run_proc(t_mp *mp, t_e *excutable, int **pipes);
void			do_builtin(t_mp *mp, char **argv, int **pipes);
void			exec_proc(char **argv, char **envp, int **pipes);
//ft_cd.c
void			ft_cd(t_mp *mp, char *dir);
char			*set_dir(char *dir, char *home, char *pwd, char *oldpwd);
void			set_value(t_mp *mp, char *target, char *value);
//exec_util.c
void			set_recent_exit_code(t_mp *mp);
char			**lst_to_arr(t_list *lst);
char			*find_value(t_mp *mp, char *target);
void			print_errno(int err, char **argv);
void			exit_pid(t_mp *mp, int i);
//set_envp.c
void			up_shlvl(t_list *envp);
char			**set_envp(t_mp *mp, char *cmd);
//set_exec.c
int				check_builtin(char *cmd);
char			**set_argv(t_mp *mp, char **argv);
char			**path_value(t_mp *mp);
char			*find_path(t_mp *mp, char *cmd);
//ft_echo.c
int				ft_echo(char *argv[], int **pipes);
int				check_n(char *argv[]);
//ft_env.c ft_pwd.c ft_exit.c
int				ft_env(t_mp *mp, int **pipes);
int				ft_pwd(t_mp *mp, int **pipes);
void			ft_exit(char **argv);
//ft_export.c
int				ft_export(t_mp *mp, char **argv, int **pipes);
int				not_valid_identifier(char *cmd, char *str);
void			print_env(t_list *envp, int **pipes);
void			add_env(t_list *envp, char **str);
t_list			*sort_env(t_list *envp);
//ft_unset.c
int				ft_unset(t_mp *mp, char **target);
void			free_target(t_list *temp);
//pipes_util.c
int				is_ltoken(t_list *rd);
int				is_rtoken(t_list *rd);
//pipes.c
int				**init_pipe(t_r *runnable);
void			set_pipes(t_r *runnable, int **pipes);
void			set_rredirect(t_list *rd, int **pipes);
void			set_lredirect(t_list *rd, int **pipes);

#endif	
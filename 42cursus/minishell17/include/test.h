/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:42:31 by snoh              #+#    #+#             */
/*   Updated: 2022/10/23 20:41:01 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "libftprintf.h"
# include "collector.h"
# include <limits.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

# define DEBUG 0


//# include <readline/readline.h>
//# include <readline/history.h>



/*
enum	e_text_label_num
{
	pipe			= "pipe"[0],
	text			= "text"[0],
	quote			= "quote"[0],
	double_quote	= "double_quote"[0],
	redirection		= "redirection"[0],
	ledirection		= "ledirection"[0],
	space			= "space"[0]
};
*/

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




int splited_2_strlist(t_list **list, char **splited);


// const_dest.c
void print_strlist(t_list *lst, char * name);
void print_splited(char **splited, char *name);



#endif	
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_3_1_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:37:52 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 07:01:33 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_token(t_token *token);
t_token	*new_token(char atype, char *atext);
void	print_token(t_token *token, char *name, int tabs);
int		tokenize(char *text, t_list **token_start);
t_list	*label2token(char *text, char *labels);
int		connect_token(t_list **token_start, t_list *token_node);
t_list	*make_token_here(char *text, char *labels, int i);
int		check_label(char *labels);
char	*label_text(char *text);
void	mark_quote(char *text, char *labels, int *idx, int len);
void	mark_not_quote(char *text, char *labels, int i);
int		check_token(t_list *token_start);
void	print_token_list(t_list *token_start, char *list_name);

void	destroy_token(t_token *token)
{
	if (token->text)
		free(token->text);
	free(token);
}

t_token	*new_token(char atype, char *atext)
{
	t_token	*r;

	r = ft_calloc(sizeof(t_token), 1);
	if (r)
	{
		r->type = atype;
		r->text = atext;
	}
	return (r);
}

void	print_token(t_token *token, char *name, int tabs)
{
	static char	n[1000];

	ft_bzero(n, 1000);
	ft_memset(n, '\t', int_min(tabs, 999));
	n[int_min(tabs, 999) + 1] = 0;
	if (token)
	{
		ft_printf("%sprint token : %s \n", n, name);
		ft_printf("%s\t%s->type = %c\n", n, name, token->type);
		ft_printf("%s\t%s->text = %s\n", n, name, token->text);
	}
	else
	{
		ft_printf("%stoken %s is (null) : t \n", n, name);
	}
}

int	tokenize(char *text, t_list **token_start)
{
	char	*labels;

	labels = label_text(text);
	if (check_label(labels))
	{
		free(labels);
		return (1);
	}
	*token_start = label2token(text, labels);
	free(labels);
	if (check_token(*token_start))
	{
		ft_lstclear(token_start, (void (*)(void *)) destroy_token);
		return (1);
	}
	return (0);
}

int	check_token(t_list *p)
{
	int		command_flag;

	command_flag = 1;
	while (p)
	{
		if (((t_token *)p->content)->type == "pipe"[0])
		{
			if (0 < command_flag)
				command_flag = -1;
			if (!p->next || ((t_token *)p->next->content)->type == "pipe"[0])
				return (1);
		}
		if (((t_token *)p->content)->type == "redirection"[0]
			|| ((t_token *)p->content)->type == "ledirection"[0])
		{
			if (0 < command_flag)
				command_flag = 2;
			if (p->next && ((t_token *)p->next->content)->type != "text"[0])
				return (1);
		}
		if (0 < command_flag)
			command_flag--;
		p = p->next;
	}
	return (command_flag);
}

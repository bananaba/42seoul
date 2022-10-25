/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_1_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:37:52 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 03:55:47 by balee            ###   ########.fr       */
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

void	mark_quote(char *text, char *labels, int *idx, int len)
{
	char	q;
	char	l;

	if (ft_isquote(text[*idx]))
	{
		q = text[*idx];
		if (q == '\'')
			l = "qoute"[0];
		else
			l = "double_quote"[0];
		labels[(*idx)++] = l;
		while (*idx <= len)
		{
			labels[*idx] = l;
			if (text[*idx] == q)
				return ;
			(*idx)++;
		}
	}
	return ;
}

/*
** Parameter    : 	1. 셸의 입력 텍스트
**					2. 입력중인 라벨
**					3. 처리중인 텍스트와 라벨의 위치 
** Return value : 없음
** Description  :	i위치의 text를 보고 |, <, >, <space>, etc 에 따라서
**					각각, 문자         p, l, r,       s,   t 를 labels의 해당 위치에 넣는다. 
** 완성됨
*/
void	mark_not_quote(char *text, char *labels, int i)
{
	if (text[i] == '|')
		labels[i] = "pipe"[0];
	else if (text[i] == '>')
		labels[i] = "redirection"[0];
	else if (text[i] == '<')
		labels[i] = "ledirection"[0];
	else if (text[i] == ' ')
		labels[i] = "space"[0];
	else
		labels[i] = "text"[0];
}

void	print_token_list(t_list *token_start, char *list_name)
{
	int	i;
	int	len;

	i = -1;
	len = ft_lstsize(token_start);
	while (++i < len)
		print_token(ft_lstnth(token_start, i)->content, list_name, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_3_1_tokenize2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:37:52 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 06:40:10 by balee            ###   ########.fr       */
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

t_list	*label2token(char *text, char *labels)
{
	int		i;
	int		len;
	t_list	*token_node;
	t_list	*token_start;

	token_start = 0;
	len = ft_strlen(text);
	i = 0;
	if (labels[i] != 's')
	{
		token_node = make_token_here(text, labels, i);
		if (connect_token(&token_start, token_node))
			return (0);
	}
	while (++i < len)
	{
		if (labels[i] != 's' && labels[i - 1] != labels[i])
		{
			token_node = make_token_here(text, labels, i);
			if (connect_token(&token_start, token_node))
				return (0);
		}
	}
	return (token_start);
}

int	connect_token(t_list **token_start, t_list *token_node)
{
	if (token_node == 0 || token_start == 0)
	{
		ft_lstclear(token_start, (void (*)(void *)) destroy_token);
		ft_lstdelone(token_node, (void (*)(void *)) destroy_token);
		return (1);
	}
	else
	{
		ft_lstadd_back(token_start, token_node);
		return (0);
	}
}

t_list	*make_token_here(char *text, char *labels, int i)
{
	int		len;
	t_token	*token;
	t_list	*node;

	len = 0;
	while (labels[i + len] == labels[i])
		len++;
	node = ft_lstnew(0);
	token = new_token(0, 0);
	if (token)
	{
		token->text = ft_substr(text, i, len);
		token->type = labels[i];
	}
	if (!(node && token && token->text))
	{
		free(node);
		destroy_token(token);
		return (0);
	}
	else
	{
		node->content = token;
		return (node);
	}
}

int	check_label(char *labels)
{
	int	len;

	len = ft_strlen(labels);
	if (ft_strnstr(labels, "pp", len))
		return (1);
	if (ft_strnstr(labels, "rl", len) != 0
		|| ft_strnstr(labels, "lr", len) != 0)
		return (1);
	if (ft_strnstr(labels, "rrr", len) != 0
		|| ft_strnstr(labels, "lll", len) != 0)
		return (1);
	if (ft_strlen_s(labels, "prlqdt") == (size_t) len)
		return (1);
	return (0);
}

char	*label_text(char *text)
{
	int		i;
	int		stat;
	int		len;
	char	*labels;

	len = ft_strlen(text);
	if (len == 0)
		return (0);
	labels = ft_calloc(sizeof(char), len + 2);
	i = -1;
	stat = 0;
	while (++i < len && labels)
	{
		if (ft_isquote(text[i]))
			mark_quote(text, labels, &i, len);
		else
			mark_not_quote(text, labels, i);
	}
	if (labels && labels[len])
	{
		free (labels);
		return (0);
	}
	return (labels);
}

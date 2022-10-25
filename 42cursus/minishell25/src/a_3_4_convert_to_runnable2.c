/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_3_4_convert_to_runnable2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 03:47:19 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 07:13:18 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_pipe_in_tokens(t_list *token_start);
void	token_2_listarray(t_list **listarray, t_list *token_start);
t_list	**convert_token_2_listarray(t_list *token_start);
int		convert_to_runnable(t_mp *mp, t_list **token_start);
t_e		*exchange_token_2_excutable(t_list **token_start, t_list *envp);
void	move_redirection_tokens(t_e *excutable, t_list **token_start);
void	*token_2_string(void *pointer);
int		make_argv(t_e *excutable, t_list **token_start);

t_list	**convert_token_2_listarray(t_list *token_start)
{
	int		num_pipe;
	t_list	**listarray;

	num_pipe = count_pipe_in_tokens(token_start);
	listarray = ft_calloc(sizeof(t_list *), num_pipe + 2);
	if (listarray)
	{
		listarray[num_pipe + 1] = 0;
		token_2_listarray(listarray, token_start);
	}
	return (listarray);
}

void	token_2_listarray(t_list **listarray, t_list *token_start)
{
	int		i;
	t_list	*now;
	t_list	*prev;
	t_token	*now_token;

	i = -1;
	now = token_start;
	listarray[++i] = token_start;
	while (now)
	{
		now_token = (t_token *)now->content;
		if (now_token->type == "pipe"[0])
		{
			prev->next = 0;
			prev = now;
			now = now->next;
			ft_lstdelone(prev, (void (*)(void *)) destroy_token);
			listarray[++i] = now;
		}
		prev = now;
		now = now->next;
	}
}

int	count_pipe_in_tokens(t_list *token_start)
{
	int		num_pipe;
	t_list	*p;

	num_pipe = 0;
	p = token_start;
	while (p)
	{
		if (((t_token *) p->content)->type == "pipe"[0])
			num_pipe++;
		p = p->next;
	}
	return (num_pipe);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_3_4_convert_to_runnable.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:56:05 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 07:13:01 by balee            ###   ########.fr       */
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

int	convert_to_runnable(t_mp *mp, t_list **token_start)
{
	int		i;
	t_list	**token_listarray;
	t_r		*runnable;

	runnable = new_runnable_with_size(count_pipe_in_tokens(*token_start) + 1);
	token_listarray = convert_token_2_listarray(*token_start);
	if (token_listarray && runnable)
	{
		i = -1;
		while (token_listarray[++i])
			runnable->excutables[i]
				= exchange_token_2_excutable(&token_listarray[i], mp->envp);
	}
	if (token_listarray)
	{
		free(token_listarray);
		token_listarray = 0;
	}
	mp->runnable = runnable;
	return (0);
}

t_e	*exchange_token_2_excutable(t_list **token_start, t_list *envp)
{
	t_e	*excutable;

	excutable = new_excutable(envp);
	if (excutable)
	{
		move_redirection_tokens(excutable, token_start);
		make_argv(excutable, token_start);
	}
	return (excutable);
}

int	make_argv(t_e *excutable, t_list **token_start)
{
	t_list	*text_list;

	text_list = 0;
	text_list = ft_lstmap(*token_start, token_2_string, free);
	ft_lstclear(token_start, do_nothing);
	if (text_list)
	{
		excutable->argv = (char **) linkedlist_2_array(&text_list);
		return (0);
	}
	else
	{
		ft_lstclear(token_start, (void (*)(void *)) destroy_token);
		return (1);
	}
}

void	*token_2_string(void *pointer)
{
	t_token	*token;
	char	*r;

	token = (t_token *)pointer;
	r = 0;
	if (token)
	{
		r = token->text;
		token->text = 0;
		free(token);
	}
	return (r);
}

void	move_redirection_tokens(t_e *excutable, t_list **token_start)
{
	int		i;
	t_list	*now;
	t_token	*now_token;

	i = 0;
	while (ft_lstnth(*token_start, i))
	{
		now = ft_lstnth(*token_start, i);
		now_token = (t_token *) now->content;
		if (now_token->type == 'r' || now_token->type == 'l')
		{
			ft_lstadd_back(&(excutable->redirections),
				ft_lstpop_nth_p(token_start, i));
			ft_lstadd_back(&(excutable->redirections),
				ft_lstpop_nth_p(token_start, i));
		}
		else
		{
			i++;
		}
	}
}

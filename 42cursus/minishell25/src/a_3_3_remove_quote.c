/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_3_3_remove_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:53:09 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 06:28:28 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	remove_quote(t_list *token_start);
int	remove_quote_token(t_token *quote_token);

int	remove_quote(t_list *token_start)
{
	t_list	*now;
	t_token	*now_token;

	now = token_start;
	while (now)
	{
		now_token = (t_token *) now->content;
		if (DEBUG)
			print_token(now_token, "now_token", 0);
		if (now_token->type == "quote"[0]
			|| now_token->type == "double_quote"[0])
		{
			remove_quote_token(now_token);
			now_token->type = "text"[0];
		}
		if (DEBUG)
			print_token(now_token, "processed_token", 1);
		now = now->next;
	}
	return (0);
}

int	remove_quote_token(t_token *quote_token)
{
	char	*str;
	int		len;

	str = quote_token->text;
	len = ft_strlen(str);
	ft_strlcpy(str, &str[1], len - 1);
	return (0);
}

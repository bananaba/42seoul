/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:37:30 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 06:33:57 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	split_text(t_list *lst);

int	divide_text_in_token(t_list *token_start)
{
	split_text(token_start);
	return (0);
}

static t_token	*mc_new_token(char atype, char *atext)
{
	t_token	*r;

	r = mc_calloc(sizeof(t_token), 1);
	if (r)
	{
		r->type = atype;
		r->text = atext;
	}
	return (r);
}

static void	split_text(t_list *lst)
{
	t_list	*temp;
	char	**str;
	int		i;

	while (lst)
	{
		if (((t_token *)lst->content)->type == 't'
			&& ft_strchr(((t_token *)lst->content)->text, ' '))
		{
			i = 0;
			str = mc_split(((t_token *)lst->content)->text, ' ');
			mc_free(((t_token *)lst->content)->text);
			((t_token *)lst->content)->text = mc_strdup(str[0]);
			while (str[++i])
			{
				temp = (t_list *)mc_malloc(sizeof(t_list));
				temp->content = (void *) mc_new_token('t', mc_strdup(str[i]));
				temp->next = lst->next;
				lst->next = temp;
				lst = temp;
			}
		}
		lst = lst->next;
	}
}

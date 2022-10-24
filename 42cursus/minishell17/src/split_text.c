/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:33:21 by balee             #+#    #+#             */
/*   Updated: 2022/10/24 23:09:48 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_text(t_list *lst)
{
	t_list	*temp;
	char	**str;
	int		i;

	while (lst)
	{
		if (((t_token *)lst->content)->type == 't'
			&& ft_strchr(((t_token *)lst->content)->text, ' '))
		{
			i = -1;
			str = ft_split(((t_token *)lst->content)->text, ' ');
			while (str[++i])
			{
				temp = (t_list *)malloc(sizeof(t_list));
				(t_token *)temp->content = new_token('t', ft_strdup(str[i]));
				temp->next = lst->next;
				lst->next = temp;
				lst = temp;
				free(str[i]);
			}
		}
		lst = lst->next;
	}
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:33 by balee             #+#    #+#             */
/*   Updated: 2022/10/25 22:06:32 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_target(t_list *temp)
{
	t_list	*temp2;

	if (temp->next == NULL)
		return ;
	free(temp->next->content);
	temp2 = temp->next;
	temp->next = temp2->next;
	free(temp2);
	temp2 = NULL;
}

int	ft_unset(t_mp *mp, char **target)
{
	t_list	*temp;
	int		len;
	int		i;

	i = -1;
	while (target[++i])
	{
		temp = mp->envp;
		len = ft_strlen(target[i]);
		if (ft_strncmp(temp->content, target[i], len) == 0
			&& ((char *)temp->content)[len] == '=')
		{
			free(temp->content);
			temp->content = NULL;
			mp->envp = mp->envp->next;
			free(temp);
			continue ;
		}
		while (temp->next != NULL
			&& !(ft_strncmp(temp->next->content, target[i], len) == 0
				&& ((char *)temp->next->content)[len] == '='))
			temp = temp->next;
		free_target(temp);
	}
	return (errno);
}

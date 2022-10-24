/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:33 by balee             #+#    #+#             */
/*   Updated: 2022/10/24 19:54:33 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_target(t_list *temp)
{
	t_list	*temp2;

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

	while (*target)
	{
		temp = mp->envp;
		len = ft_strlen(*target);
		if (ft_strncmp(temp->content, *target, len) == 0)
		{
			free(temp->content);
			temp->content = NULL;
			mp->envp = mp->envp->next;
			free(temp);
			return (errno);
		}
		while (temp->next != NULL
			&& ft_strncmp(temp->next->content, *target, len))
			temp = temp->next;
		if (temp->next == NULL)
			return (errno);
		free_target(temp);
		target = target + 1;
	}
	return (errno);
}

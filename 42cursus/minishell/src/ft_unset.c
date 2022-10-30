/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:33 by balee             #+#    #+#             */
/*   Updated: 2022/10/27 20:47:30 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_target(t_list *temp)
{
	t_list	*temp2;

	if (temp->next == NULL)
		return ;
	mc_free(temp->next->content);
	temp2 = temp->next;
	temp->next = temp2->next;
	mc_free(temp2);
	temp2 = NULL;
}

int	check_content(char *content, char *target)
{
	int	len;

	len = ft_strlen(target);
	if (ft_strncmp(content, target, len) == 0 && content[len] == '=')
		return (true);
	return (false);
}

int	ft_unset(t_mp *mp, char **target)
{
	t_list	*temp;
	int		i;
	int		exit_code;

	i = -1;
	exit_code = 0;
	while (target[++i])
	{
		temp = mp->envp;
		if (!ft_isalpha(target[i][0]) && target[i][0] != '_')
			exit_code = not_valid_identifier("unset", target[i]);
		else if (check_content(temp->content, target[i]))
		{
			mc_free(temp->content);
			mp->envp = mp->envp->next;
			mc_free(temp);
		}
		else
		{
			while (temp->next && !check_content(temp->next->content, target[i]))
				temp = temp->next;
			free_target(temp);
		}
	}
	return (exit_code);
}

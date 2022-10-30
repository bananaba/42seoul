/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:51:33 by balee             #+#    #+#             */
/*   Updated: 2022/10/27 22:30:03 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	up_shlvl(t_list *envp)
{
	t_list	*temp;
	char	*lv;

	temp = envp;
	while (temp && ft_strncmp(temp->content, "SHLVL=", 6))
		temp = temp->next;
	if (temp == NULL)
		return ;
	lv = mc_itoa(ft_atoi(&((char *)temp->content)[6]) + 1);
	mc_free(temp->content);
	temp->content = mc_strjoin("SHLVL=", lv);
	mc_free(lv);
}

char	**set_envp(t_mp *mp, char *cmd)
{
	char	**envp;
	t_list	*new;
	t_list	*last;

	new = mc_lstnew(ft_strjoin("_=", cmd));
	last = ft_lstlast(mp->envp);
	ft_lstadd_back(&mp->envp, new);
	envp = lst_to_arr(mp->envp);
	mc_free(new->content);
	mc_free(new);
	new = NULL;
	last->next = NULL;
	return (envp);
}

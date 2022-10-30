/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:29 by balee             #+#    #+#             */
/*   Updated: 2022/10/27 23:35:32 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_mp *mp, int **pipes)
{
	char	*pwd;
	t_list	*envp;

	envp = mp->envp;
	pwd = 0;
	while (envp)
	{
		if (ft_strncmp(envp->content, "PWD=", 4) == 0)
		{
			pwd = mc_strdup(&envp->content[4]);
			break ;
		}
		envp = envp->next;
	}
	if (pwd == NULL)
		pwd = mc_getcwd();
	ft_putendl_fd(pwd, pipes[1][1]);
	mc_free(pwd);
	return (errno);
}

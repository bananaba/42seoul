/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:29 by balee             #+#    #+#             */
/*   Updated: 2022/10/25 23:02:49 by snoh             ###   ########.fr       */
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
			pwd = ft_strdup(&envp->content[4]);
			if (pwd == NULL)
				return (errno);
			break ;
		}
		envp = envp->next;
	}
	ft_putendl_fd(pwd, pipes[1][1]);
	free(pwd);
	return (errno);
}

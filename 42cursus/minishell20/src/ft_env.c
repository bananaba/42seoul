/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:23 by balee             #+#    #+#             */
/*   Updated: 2022/10/24 19:54:24 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_mp *mp, int **pipes)
{
	t_list	*envp;

	envp = mp->envp;
	while (envp)
	{
		ft_putendl_fd(envp->content, pipes[1][1]);
		envp = envp->next;
	}
	return (errno);
}

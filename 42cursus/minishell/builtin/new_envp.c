/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:13:10 by balee             #+#    #+#             */
/*   Updated: 2022/10/19 20:13:12 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	envp_len(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

char	**sum_envp(char *envp[], char *nenvp[], char *cmd[])
{
	int		i;
	int		j;
	char	**senvp;

	i = envp_len(envp);
	j = envp_len(nenvp);
	senvp = (char **)malloc(sizeof(char *) * (i + j + 2));
	ft_bzero(senvp, sizeof(senvp));
	i = 0;
	while (envp[i])
	{
		senvp[i] = ft_strdup(envp[i]);
		i++;
	}
	j = 0;
	while (nenvp[j])
	{
		senvp[i + j] = ft_strdup(nenvp[j]);
		j++;
	}
	senvp[i + j] = ft_strdup(cmd[0]);
	return (senvp);
}

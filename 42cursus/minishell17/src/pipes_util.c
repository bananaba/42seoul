/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:37 by balee             #+#    #+#             */
/*   Updated: 2022/10/24 19:54:37 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_ltoken(t_list *rd)
{
	while (rd)
	{
		if (((t_token *)rd->content)->type == 'l')
			return (0);
		rd = rd->next;
	}
	return (1);
}

int	is_rtoken(t_list *rd)
{
	while (rd)
	{
		if (((t_token *)rd->content)->type == 'r')
			return (0);
		rd = rd->next;
	}
	return (1);
}

void	free_run(int **pipes, int i, pid_t *pid)
{
	close(pipes[i][0]);
	close(pipes[i][1]);
	while (i >= 0)
		free(pipes[i--]);
	free(pipes);
	free(pid);
}

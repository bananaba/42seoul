/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_const_dest1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:30:07 by balee             #+#    #+#             */
/*   Updated: 2022/10/28 00:36:18 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*destruct_excutable(t_e *excutable)
{
	if (excutable->redirections)
		ft_lstclear(&excutable->redirections, (void (*)(void *))destroy_token);
	ft_split_free(excutable->argv);
	excutable->argv = 0;
	excutable->envp = 0;
	free(excutable);
	return (0);
}

void	*destruct_runnable(t_r *runnable)
{
	int	i;

	i = -1;
	while (runnable->excutables && runnable->excutables[++i])
		destruct_excutable(runnable->excutables[i]);
	free(runnable->excutables);
	runnable->excutables = 0;
	free(runnable);
	return (0);
}

void	*destruct_minishell_program(t_mp *minishell_program)
{
	t_mp	*mp;

	mp = minishell_program;
	mp->initial_argv = 0;
	mp->initial_envp = 0;
	collector(&mp->mbox, 0);
	ft_lstclear(&mp->envp, mc_free);
	free(mp->command);
	mp->command = 0;
	if (mp->runnable)
		destruct_runnable(mp->runnable);
	mp->command = 0;
	free(mp->pid);
	return (0);
}

struct s_excutable	*new_excutable(t_list *envp)
{
	t_e	*r;

	r = ft_calloc(sizeof(t_e), 1);
	if (r)
	{
		r->state = 0;
		r->argv = 0;
		r->envp = envp;
		r->redirections = 0;
	}
	return (r);
}

struct s_runnable	*new_runnable(void)
{
	t_r	*r;

	r = ft_calloc(sizeof(t_r), 1);
	if (r)
	{
		r->state = 0;
		r->text = 0;
		r->num_of_excutables = 0;
		r->excutables = 0;
	}
	return (r);
}

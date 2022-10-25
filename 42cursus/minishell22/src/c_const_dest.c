/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_const_dest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:30:07 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 02:34:43 by balee            ###   ########.fr       */
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

/*
void *destruct_command(t_c *command)
{
	int i;

	i = -1;
	free(command->text);
	command->text = 0;
	while(command->runnables && command->runnables[++i])
		destruct_runnable(command->runnables[i]);
	free(command->runnables);
	command->runnables = 0;
	free(command);
	return (0);
}
*/

void	*destruct_minishell_program(t_mp *minishell_program)
{
	minishell_program->initial_argv = 0;
	minishell_program->initial_envp = 0;
	collector(&minishell_program->mbox, 0);
	ft_lstclear(&minishell_program->envp, free);
	destruct_runnable(minishell_program->runnable);
	minishell_program->command = 0;
	return (0);
}

/*
void initialize_excutable(t_e *excutable)
{
	excutable->text = 0;
	excutable->excutable_path = 0;
	excutable->redirections = 0;

	excutable->argv = 0;
	excutable->envp = 0;

	excutable->num_of_input_redirects = 0;
	excutable->num_of_output_redirects = 0;

	excutable->input_redirect_flag = 0;
	excutable->input_redirect = 0;

	excutable->output_redirect_flag = 0;
	excutable->output_redirect = 0;

	state = 0;
}
*/

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

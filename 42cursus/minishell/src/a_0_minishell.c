/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_0_minishell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/28 02:17:16 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	post(t_mp *mp)
{
	if (mp->error_flag != 0 || !mp->runnable)
		return (0);
	destruct_runnable(mp->runnable);
	mp->runnable = 0;
	return (0);
}

void	handle_error(t_mp *mp)
{
	if (mp->error_flag == 1)
		ft_eprintf("error : The syntax error.\n");
	else if (mp->error_flag == 2)
		ft_eprintf("error : Variable extension failed.\n");
	else if ("When only EOF came in" && mp->error_flag == 42)
		return ;
	mp->error_flag = 0;
	return ;
}

void	ready_for_exit(t_mp *mp)
{
	memorybox("dest", 0);
	destruct_minishell_program(mp);
}

int	main(int argc, char **argv, char **envp)
{
	struct s_minishell_program	*mp;

	if (initialize(&mp, argc, argv, envp))
		return (1);
	while (mp->error_flag == 0)
	{
		prompt(mp);
		parse(mp);
		run(mp);
		post(mp);
		handle_error(mp);
	}
	ready_for_exit(mp);
	return (0);
}

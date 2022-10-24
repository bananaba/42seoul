/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_minishell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/03 17:32:50 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int process_command(t_mp *mp);
int run_commands_in_order(t_mp *mp/*->command*/) ;
int is_nextrun_available(t_mp *mp, t_r **runnable);
int command_to_jobs(t_c *command);

int	main(int argc, char **argv, char **envp)
{
	struct s_minishell_program *mp;

	if (initialize(&mp, argc, argv, envp))
		return(1);
	while (mp->error_flag == 0)
	{
		prompt(mp);
		process_command(mp);
	}

	//ready_for_exit(mp);
	return (0);
}


int process_command(t_mp *mp)
{
	//parse_structure(); 				for bonus

	command_to_jobs(mp->command);
	run_commands_in_order(mp);
	
	//post_process(mp/*->command*/)

	//processing...
	return (0);
}

int run_commands_in_order(t_mp *mp/*->command*/) // 보너스 때문에
{
	t_r *runnable;

	while(is_nextrun_available(mp, &runnable))
	{
		parse(mp, runnable);
		run(mp, runnable); //<< 여기!!
		//post_process(mp, runnable); //exitcode 같은거?

	}
	return (0);
}

int is_nextrun_available(t_mp *mp, t_r **runnable)// runnable은 하나만 나올 떄를 가정하고 임시로 만듦
{
	if (mp->command->state == 0)
	{
		*runnable = mp->command->runnables[0];
		mp->command->state++;
		return(1);
	}
	else
		return(0);

}


int command_to_jobs(t_c *command)
{
	command -> num_of_runnables = 1;
	command -> runnables = ft_calloc(sizeof(t_r *), 1 + 1);
	command -> runnables[0] = ft_calloc(sizeof(t_r), 1);
	command -> runnables[0]->text = ft_strdup(command->text);
	command -> runnables[0]->state = 0;
	return (0);
}


int run(t_mp *mp, t_r *runnable)
{
	int i;
	int j;

	i = -1;
	while(runnable->excutables[++i])
	{
		j = -1;
		while (runnable->excutables[i]->argv[++j])
			ft_printf("argv[%d]:%s\n", j, runnable->excutables[i]->argv[j]);

	}
return (0);	
}
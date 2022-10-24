/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/01 23:12:23 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int prompt(t_mp *mp)
{

	//s = malloc(1);
	//while(s)
	{
		//free(s);
		destruct_command(mp->command);
		mp->command = ft_calloc(sizeof(t_c), 1);
		getcwd(mp->pwd, 9999);
		ft_sprintf(mp->pwd, "%s %% ", mp->pwd);
		mp->command->text = readline(mp->pwd);
		if (mp->command->text == 0)
			exit_by_error(0);
		//free(prompt);
		//printf("%s\n", s);
		add_history(mp->command->text);
		return (0);
	}
	

	// if minishell run non-interactive mode, then skip prompt 

	// get command from user
	// and save it on mp->command.text
	// and change mp->command.state
}




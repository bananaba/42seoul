/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_2_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/24 17:48:33 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int prompt(t_mp *mp)
{
	while (1)
	{
		free(mp->command);
		getcwd(mp->pwd, 9999);
		ft_sprintf(mp->pwd, "%s %% ", mp->pwd);
		mp->command = readline(mp->pwd);
		if (mp->command == 0)
		{
			mp->error_flag = 2;
			return (0);
		}
		if (ft_strlen(mp->command) == 0)
		{
			continue ;
		}
		add_history(mp->command);
		return (0);
	}
	

	// if minishell run non-interactive mode, then skip prompt 

	// get command from user
	// and save it on mp->command.text
	// and change mp->command.state
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_2_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 06:22:23 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prompt(t_mp *mp)
{
	while (1)
	{
		free(mp->command);
		mp->command = 0;
		getcwd(mp->pwd, 9999);
		ft_sprintf(mp->pwd, "%s %% ", mp->pwd);
		mp->command = readline(mp->pwd);
		if (mp->command == 0)
		{
			mp->error_flag = 42;
			return (0);
		}
		if (ft_strlen(mp->command) == 0)
		{
			continue ;
		}
		add_history(mp->command);
		return (0);
	}
}

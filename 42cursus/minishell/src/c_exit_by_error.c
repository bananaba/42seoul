/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_exit_by_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:35:23 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 06:33:35 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_by_error(int code)
{
	static t_mp	*mp;

	if (code == -100)
	{
		mp = memorybox("pop", 0);
		return ;
	}
	memorybox("dest", 0);
	destruct_minishell_program(mp);
	exit(code);
}

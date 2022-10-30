/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:47:54 by balee             #+#    #+#             */
/*   Updated: 2022/10/27 22:48:25 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*mc_getcwd(void)
{
	char	*r;

	r = getcwd(NULL, 0);
	if (r)
	{
		memorybox("add", r);
		return (r);
	}
	else
	{
		exit_by_error(1);
		return (0);
	}
}

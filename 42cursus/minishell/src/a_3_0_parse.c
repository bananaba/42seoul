/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_3_0_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/28 01:26:31 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(t_mp *mp)
{
	t_list	*token_start;

	if (mp->error_flag)
		return ;
	token_start = 0;
	if (tokenize(mp->command, &token_start))
	{
		mp->error_flag = 1;
		return ;
	}
	if (variable_expansion(token_start, mp->envp))
	{
		mp->error_flag = 2;
		return ;
	}
	divide_text_in_token(token_start);
	remove_quote(token_start);
	convert_to_runnable(mp, &token_start);
}

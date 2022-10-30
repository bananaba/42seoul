/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_memory_manage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/28 02:50:32 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*collector(t_mbox *box, void *pointer)
{
	if (box == 0)
		return (pointer);
	if (pointer)
	{
		box->tape[box->cur++] = pointer;
	}
	else
	{
		while (box->cur--)
		{
			free(box->tape[box->cur]);
		}
		box->cur = 0;
	}
	return (pointer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_memory_manage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 02:35:36 by balee            ###   ########.fr       */
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

/*
void	*collector_f(t_mbox *box, void *pointer, void (*destroyer)(void *))
{
	if (box == 0)
		return (pointer);
	if (pointer || destroyer)
	{
		box->tape[box->cur++] = pointer;
		box->tape[box->cur++] = destroyer;
	}
	else
	{

		while (box->cur----)
		{
			((void *(*)(void *))(box->tape[box->cur + 1]))(box->tape[box->cur])
		}
		box->cur = 0;
	}
	return (pointer);
}
*/

/*
void	*collector(void *pointer)
{
	static int	cur;
	static void	*tape[10000];

	if (pointer)
	{
		tape[cur++] = pointer;
	}
	else
	{
		while (cur--)
		{
			free(tape[cur]);
		}
		cur = 0;
	}
	return (pointer);
}
*/


/*
void	*mutex_collector(void *pointer)
{
	static int	cur;
	static void	*tape[10000];

	if (pointer)
	{
		tape[cur++] = pointer;
	}
	else
	{
		while (cur--)
		{
			pthread_mutex_destroy(tape[cur]);
		}
		cur = 0;
	}
	return (pointer);
}
*/
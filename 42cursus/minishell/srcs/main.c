<<<<<<< HEAD
#include "../includes/minishell.h"

void	set_signal(void)
{
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:09:44 by balee             #+#    #+#             */
/*   Updated: 2022/10/13 18:26:47 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sigint_handler(int signum)
{
}

void	sigquit_handler(int signum)
{
}

void	signal_management(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
>>>>>>> 2183582307fddd61af012c9472c871e9f73ce7f8
}

int	main(void)
{
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:12:59 by balee             #+#    #+#             */
/*   Updated: 2022/10/19 20:56:01 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_err(void)
{
	if (errno == 0)
		return ;
	write(2, "Error : ", 8);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	write(1, "\0", 1);
	exit (errno);
}

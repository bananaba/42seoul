/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:12:59 by balee             #+#    #+#             */
/*   Updated: 2022/10/19 19:13:02 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_err(void)
{
	if (errno == 0)
		return ;
	printf("Error : %s\n", strerror(errno));
	exit (errno);
}

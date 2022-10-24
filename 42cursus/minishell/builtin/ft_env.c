<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:08:46 by balee             #+#    #+#             */
/*   Updated: 2022/10/19 17:08:47 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
>>>>>>> b2e2fc83eaaabc95589be59b8de7883a22617cd1
#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
<<<<<<< HEAD
	int	i;

	i = 0;
=======
	int	i = 0;

>>>>>>> b2e2fc83eaaabc95589be59b8de7883a22617cd1
	while (envp[i])
		printf("%s\n", envp[i++]);
	return (errno);
}

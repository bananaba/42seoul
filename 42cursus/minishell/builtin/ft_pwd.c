<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:08:51 by balee             #+#    #+#             */
/*   Updated: 2022/10/19 17:09:38 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
>>>>>>> b2e2fc83eaaabc95589be59b8de7883a22617cd1
#include "../includes/minishell.h"

int	main(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
<<<<<<< HEAD
	printf("%s\n");
	free(pwd);
=======
	if (pwd != NULL)
	{
		printf("%s\n", pwd);
		free(pwd);
		pwd = NULL;
	}
>>>>>>> b2e2fc83eaaabc95589be59b8de7883a22617cd1
	return (errno);
}

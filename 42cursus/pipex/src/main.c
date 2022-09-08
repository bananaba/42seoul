/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:59:16 by balee             #+#    #+#             */
/*   Updated: 2022/08/25 18:35:10 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_err(int err)
{
	if (err == 0 && errno == 0)
		return ;
	else if (err != 0 && errno != err)
		errno = err;
	perror("Error");
	exit(errno);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		check_err(8);
	parse(argc - 1, argv, envp, &pipex);
	set_cmd(&pipex);
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	make_pipe(argc - 3, envp, &pipex);
	safe_exit(&pipex);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:58 by balee             #+#    #+#             */
/*   Updated: 2022/09/11 16:01:20 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		err;

	if (argc != 5 && argc != 6)
		return (print_error(ENOEXEC));
	err = init_philo(&data, argc, argv);
	if (err)
		return (print_error(err));
	err = philo_start(&data);
	if (err)
		return (print_error(err));
	return (SUCCESS);
}

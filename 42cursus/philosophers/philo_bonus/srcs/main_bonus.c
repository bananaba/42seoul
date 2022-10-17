/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:58 by balee             #+#    #+#             */
/*   Updated: 2022/10/17 17:54:06 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	monitoring_all_eat(t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->info[NUM_OF_PHILOS])
		sem_wait(data->eaten);
	sem_post(data->finish);
	sem_wait(data->print);
	printf("All philosophers have eaten enough\n");
}

int	main(int argc, char **argv)
{
	t_data	data;
	pid_t	monitor;

	if (argc != 5 && argc != 6)
		exit_err(ENOEXEC);
	init_philo(&data, argc, argv);
	philo_start(&data);
	if (data.info[NUM_OF_MUST_EAT] != -1)
	{
		monitor = fork();
		if (monitor == 0)
			monitoring_all_eat(&data);
	}
	sem_wait(data.finish);
	if (data.info[NUM_OF_MUST_EAT] != -1)
		kill(monitor, SIGINT);
	clean_up(&data);
	return (SUCCESS);
}

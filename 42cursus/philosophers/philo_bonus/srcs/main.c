/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:58 by balee             #+#    #+#             */
/*   Updated: 2022/10/10 03:03:12 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitoring_all_eat(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info[NUM_OF_PHILOS])
	{
		sem_wait(data->full);
		i++;
	}
	sem_wait(data->print);
	sem_post(data->finish);
	printf("All philosophers have eaten enough\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor;

	if (argc != 5 && argc != 6)
		exit_err(ENOEXEC);
	init_philo(&data, argc, argv);
	philo_start(&data);
	if (data.info[NUM_OF_MUST_EAT] != -1)
		pthread_create(&monitor, NULL, (void *)&monitoring_all_eat, &data);
	sem_wait(data.finish);
	clean_up(&data);
	return (SUCCESS);
}

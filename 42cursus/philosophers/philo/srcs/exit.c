/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:45 by balee             #+#    #+#             */
/*   Updated: 2022/10/13 17:51:43 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_all(t_data *data)
{
	free(data->philos);
	free(data->forks);
	data->philos = NULL;
	data->forks = NULL;
}

void	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info[NUM_OF_PHILOS])
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].eating);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->finish);
}

void	detach_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info[NUM_OF_PHILOS])
		pthread_join(data->philos[i++].tid, NULL);
}

void	clean_up(t_data *data)
{
	detach_all(data);
	destroy_all(data);
	free_all(data);
}

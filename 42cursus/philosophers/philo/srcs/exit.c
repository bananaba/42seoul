/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:45 by balee             #+#    #+#             */
/*   Updated: 2022/09/11 16:16:17 by balee            ###   ########.fr       */
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
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->eating);
}

void	detach_all(t_data *data)
{
	int	i;
	int	result;

	i = 0;
	while (i < data->info[NUM_OF_PHILOS])
		pthread_join(data->philos[i++].tid, (void *)&result);
}

void	clean_up(t_data *data)
{
	detach_all(data);
	destroy_all(data);
	free_all(data);
}

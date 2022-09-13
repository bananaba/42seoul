/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:06:03 by balee             #+#    #+#             */
/*   Updated: 2022/09/12 15:48:41 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->first]);
	print_str("has taken a fork", data, philo);
	pthread_mutex_lock(&data->forks[philo->second]);
	print_str("has taken a fork", data, philo);
	print_str("is eating", data, philo);
	philo->eat_time = time_in_ms();
	usleep(data->info[TIME_TO_EAT] * 500);
	while (time_in_ms() - philo->eat_time < data->info[TIME_TO_EAT])
		usleep(0);
	pthread_mutex_unlock(&data->forks[philo->first]);
	pthread_mutex_unlock(&data->forks[philo->second]);
	philo->eat_cnt++;
	if (data->info[NUM_OF_MUST_EAT] == philo->eat_cnt)
	{
		pthread_mutex_lock(&data->eating);
		data->eat++;
		pthread_mutex_unlock(&data->eating);
	}
}

void	*philo_routine(t_philo *philo)
{
	long long	sleep_time;

	if (philo->data->info[TIME_TO_DIE] == 0)
		return (NULL);
	if (philo->num % 2 == 0 && philo->data->info[TIME_TO_EAT] == 0)
		usleep(500);
	else if (philo->num % 2 == 0)
		usleep(philo->data->info[TIME_TO_EAT] * 900);
	while (!philo->data->fin)
	{
		philo_eat(philo, philo->data);
		sleep_time = time_in_ms();
		print_str("is sleeping", philo->data, philo);
		usleep(philo->data->info[TIME_TO_SLEEP] * 500);
		while (time_in_ms() - sleep_time < philo->data->info[TIME_TO_SLEEP])
			usleep(0);
		print_str("is thinking", philo->data, philo);
	}
	return (NULL);
}

void	monitoring(t_data *data)
{
	int			i;
	long long	time;

	while (!data->fin && data->eat < data->info[NUM_OF_PHILOS])
	{
		i = 0;
		time = time_in_ms();
		while (i++ < data->info[NUM_OF_PHILOS] && !data->fin)
		{
			if (time - data->philos[i - 1].eat_time >= data->info[TIME_TO_DIE])
			{
				pthread_mutex_lock(&data->print);
				printf("%lldms %d died\n", time_in_ms() - data->time, i);
				data->fin++;
				break ;
			}
		}
	}
	if (!data->fin)
	{
		pthread_mutex_lock(&data->print);
		printf("All philosophers have eaten enough\n");
		data->fin++;
	}
	pthread_mutex_unlock(&data->print);
}

int	philo_start(t_data *data)
{
	int			i;
	t_philo		*temp;

	i = 0;
	while (i < data->info[NUM_OF_PHILOS])
	{
		temp = &data->philos[i];
		if (pthread_create(&temp->tid, NULL, (void *)&philo_routine, temp))
		{
			while (i-- > 0)
				pthread_detach(data->philos[i].tid);
			destroy_all(data);
			free_all(data);
			return (EAGAIN);
		}
		i++;
	}
	monitoring(data);
	clean_up(data);
	return (SUCCESS);
}

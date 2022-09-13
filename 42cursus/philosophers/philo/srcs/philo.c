/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:06:03 by balee             #+#    #+#             */
/*   Updated: 2022/09/13 16:20:26 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->first]);
	print_str("has taken a fork", data, philo);
	if (data->info[NUM_OF_PHILOS] == 1)
	{
		usleep(data->info[TIME_TO_DIE] * 1000);
		pthread_mutex_unlock(&data->forks[philo->first]);
		return ;
	}
	pthread_mutex_lock(&data->forks[philo->second]);
	print_str("has taken a fork", data, philo);
	print_str("is eating", data, philo);
	philo->eat_time = time_in_ms();
	philo->eat_cnt++;
	usleep(data->info[TIME_TO_EAT] * 900);
	while (time_in_ms() - philo->eat_time < data->info[TIME_TO_EAT])
		usleep(100);
	pthread_mutex_unlock(&data->forks[philo->first]);
	pthread_mutex_unlock(&data->forks[philo->second]);
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
	while (!fin_num(philo->data))
	{
		philo_eat(philo, philo->data);
		sleep_time = time_in_ms();
		print_str("is sleeping", philo->data, philo);
		usleep(philo->data->info[TIME_TO_SLEEP] * 900);
		while (time_in_ms() - sleep_time < philo->data->info[TIME_TO_SLEEP])
			usleep(100);
		print_str("is thinking", philo->data, philo);
		usleep(100);
	}
	return (NULL);
}

void	check_philos(t_data *data)
{
	int			i;
	long long	time;

	i = 0;
	time = time_in_ms();
	while (i++ < data->info[NUM_OF_PHILOS] && !data->fin)
	{
		if (time - data->philos[i - 1].eat_time >= data->info[TIME_TO_DIE])
		{
			pthread_mutex_lock(&data->print);
			printf("%lldms %d died\n", time_in_ms() - data->time, i);
			pthread_mutex_lock(&data->finish);
			data->fin++;
			pthread_mutex_unlock(&data->finish);
		}
		if (data->philos[i - 1].eat_cnt >= data->info[NUM_OF_MUST_EAT]
			&& data->info[NUM_OF_MUST_EAT] >= 0)
			data->eat++;
	}
}

void	monitoring(t_data *data)
{
	while (!data->fin)
	{
		data->eat = 0;
		check_philos(data);
		if (data->eat == data->info[NUM_OF_PHILOS] && !data->fin)
		{
			pthread_mutex_lock(&data->print);
			printf("All philosophers have eaten enough\n");
			pthread_mutex_lock(&data->finish);
			data->fin++;
			pthread_mutex_unlock(&data->finish);
		}
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

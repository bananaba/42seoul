/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:06:03 by balee             #+#    #+#             */
/*   Updated: 2022/10/12 02:41:12 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitoring(t_philo *philo)
{
	long long	eat_time;

	while (1)
	{
		pthread_mutex_lock(&philo->eating);
		eat_time = philo->eat_time;
		if (time_in_ms() - eat_time >= philo->data->info[TIME_TO_DIE])
		{
			sem_wait(philo->data->print);
			sem_post(philo->data->finish);
			printf("%lldms %d died\n", time_in_ms() - philo->data->time, philo->num);
		}
		pthread_mutex_unlock(&philo->eating);
		usleep((philo->data->info[TIME_TO_DIE] - time_in_ms() + eat_time) * 900);
		while (time_in_ms() - eat_time < philo->data->info[TIME_TO_DIE])
			usleep(100);
	}
	return (NULL);
}

void	set_philo(t_philo *philo, t_data *data, int num)
{
	philo->num = num;
	philo->eat_cnt = 0;
	philo->eat_time = data->time;
	philo->data = data;
	pthread_mutex_init(&philo->eating, NULL);
}

void	eating(t_philo *philo, t_data *data)
{
	sem_wait(data->forks);
	print_str("has taken a fork", data, philo);
	sem_wait(data->forks);
	print_str("has taken a fork", data, philo);
	print_str("is eating", data, philo);
	pthread_mutex_lock(&philo->eating);
	philo->eat_time = time_in_ms();
	pthread_mutex_unlock(&philo->eating);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->data->info[NUM_OF_MUST_EAT])
		sem_post(philo->data->full);	
	usleep(data->info[TIME_TO_EAT] * 900);
	while (time_in_ms() - philo->eat_time < data->info[TIME_TO_EAT])
		usleep(100);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	philosopher(t_data *data, int num)
{
	long long	sleep_time;
	pthread_t	monitor;
	t_philo		philo;

	set_philo(&philo, data, num);
	pthread_create(&monitor, NULL, (void *)&monitoring, &philo);
	if (num > (data->info[NUM_OF_PHILOS] + 1) / 2)
		usleep(data->info[TIME_TO_EAT] * 900);
	while (1)
	{
		eating(&philo, data);
		print_str("is sleeping", data, &philo);
		sleep_time = time_in_ms();
		usleep(data->info[TIME_TO_SLEEP] * 900);
		while (time_in_ms() - sleep_time < data->info[TIME_TO_SLEEP])
			usleep(100);
		print_str("is thinking", data, &philo);
		usleep(100);
	}
}

int	philo_start(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info[NUM_OF_PHILOS])
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			exit_err(EAGAIN);
		else if (data->pid[i] == 0)
			philosopher(data, i + 1);
		i++;
	}
	return (SUCCESS);
}

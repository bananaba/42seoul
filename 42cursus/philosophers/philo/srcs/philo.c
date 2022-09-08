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
		usleep(data->info[NUM_OF_PHILOS] * 5);
	philo->eat_cnt++;
	if (data->info[NUM_OF_MUST_EAT] == philo->eat_cnt)
		data->eat++;
	pthread_mutex_unlock(&data->forks[philo->first]);
	pthread_mutex_unlock(&data->forks[philo->second]);
}

void	*philo_routine(t_philo *philo)
{
	long long	sleep_time;

	if (time_in_ms() - philo->eat_time >= philo->data->info[TIME_TO_DIE])
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
			usleep(philo->data->info[NUM_OF_PHILOS] * 5);
		print_str("is thinking", philo->data, philo);
	}
	return (NULL);
}

void	monitoring(t_data *data)
{
	int 		i;
	long long	time;

	while (!data->fin && data->eat != data->info[NUM_OF_PHILOS] && data->info[NUM_OF_MUST_EAT])
	{
		i = 0;
		time = time_in_ms();
		while (i++ < data->info[NUM_OF_PHILOS] && !data->fin)
			if (time - data->philos[i - 1].eat_time >= data->info[TIME_TO_DIE])
			{
				pthread_mutex_lock(&data->print);
				printf("%lldms %d died\n", time - data->time, i);
				data->fin++;
			}
	}
	if (!data->fin)
	{
		pthread_mutex_lock(&data->print);
		printf("All philosophers have eaten enough\n");
		data->fin++;
	}
}

int	philo_start(t_data *data)
{
	int			i;
	t_philo		*temp;

	i = 0;
	while (i < data->info[NUM_OF_PHILOS] && data->info[NUM_OF_MUST_EAT])
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
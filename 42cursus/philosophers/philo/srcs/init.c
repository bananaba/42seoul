/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:50 by balee             #+#    #+#             */
/*   Updated: 2022/09/08 13:44:14 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	set_info(t_data *data, int argc, char **argv)
{
	long long	temp;
	int			i;
	int			j;

	i = 1;
	data->info[NUM_OF_MUST_EAT] = -1;
	while (i < argc)
	{
		temp = 0;
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				temp = temp * 10 + argv[i][j] - '0';
			else
				return (EINVAL);
			if (temp > 2147483647)
				return (EINVAL);
			j++;
		}
		data->info[i - 1] = temp;
		i++;
	}
	return (SUCCESS);
}

int	malloc_all(t_data *data)
{
	int	num;

	num = data->info[NUM_OF_PHILOS];
	data->philos = (t_philo *)malloc(sizeof(t_philo) * num);
	if (data->philos == NULL)
		return (ENOMEM);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (data->forks == NULL)
	{
		free(data->philos);
		return (ENOMEM);
	}
	return (SUCCESS);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->eating, NULL);
	while (i < data->info[NUM_OF_PHILOS])
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	set_philo(t_data *data)
{
	int i;

	i = 0;
	while (i < data->info[NUM_OF_PHILOS])
	{
		data->philos[i].num = i + 1;
		data->philos[i].first = (i + 1) % data->info[NUM_OF_PHILOS];
		data->philos[i].second = i;
		data->philos[i].eat_cnt = 0;
		data->philos[i].eat_time = data->time;
		data->philos[i].data = data;
		i++;
	}
}

int	init_philo(t_data *data, int argc, char **argv)
{
	if (set_info(data, argc, argv))
		return (EINVAL);
	if (data->info[NUM_OF_PHILOS] == 0)
		return (NOPHIL);
	if (malloc_all(data))
		return (ENOMEM);
	init_mutex(data);
	data->time = time_in_ms();
	set_philo(data);
	data->fin = 0;
	data->eat = 0;
	return (SUCCESS);
}

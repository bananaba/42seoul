/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:50 by balee             #+#    #+#             */
/*   Updated: 2022/10/17 17:12:22 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	set_info(t_data *data, int argc, char **argv)
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
				exit_err(EINVAL);
			if (temp > 2147483647)
				exit_err(EINVAL);
			j++;
		}
		data->info[i - 1] = temp;
		i++;
	}
}

void	init_sem(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("finish");
	sem_unlink("eaten");
	sem_unlink("print");
	sem_unlink("start");
	data->forks = sem_open("forks", O_CREAT, 0644, data->info[NUM_OF_PHILOS]);
	data->finish = sem_open("finish", O_CREAT, 0644, 0);
	data->eaten = sem_open("eaten", O_CREAT, 0644, 0);
	data->print = sem_open("print", O_CREAT, 0644, 1);
	data->start = sem_open("start", O_CREAT, 0644, 0);
}

char	*set_name(int num)
{
	int		len;
	int		temp;
	char	*name;

	temp = 1;
	len = 0;
	while (temp <= num)
	{
		temp *= 10;
		len++;
	}
	name = (char *)malloc(sizeof(char) * (len + 1));
	if (name == NULL)
		exit_err(ENOMEM);
	name[len] = '\0';
	while (len-- > 0)
	{
		name[len] = num % 10 + '0';
		num /= 10;
	}
	return (name);
}

void	set_philo(t_philo *philo, t_data *data, int num)
{
	philo->num = num;
	philo->eat_cnt = 0;
	philo->data = data;
	philo->eat_time = data->time;
	philo->name = set_name(num);
	sem_unlink(philo->name);
	philo->eating = sem_open(philo->name, O_CREAT, 0644, 1);
}

void	init_philo(t_data *data, int argc, char **argv)
{
	int	n;

	set_info(data, argc, argv);
	if (data->info[NUM_OF_PHILOS] == 0)
		exit_err(NOPHIL);
	if (data->info[NUM_OF_MUST_EAT] == 0)
		exit_err(NONEED);
	data->pid = (pid_t *)malloc(sizeof(pid_t) * (data->info[NUM_OF_PHILOS]));
	if (data->pid == NULL)
		exit_err(ENOMEM);
	data->philo = (t_philo *)malloc(sizeof(t_philo)
			* (data->info[NUM_OF_PHILOS]));
	if (data->philo == NULL)
		exit_err(ENOMEM);
	n = 0;
	data->time = time_in_ms() + 1000;
	while (n < data->info[NUM_OF_PHILOS])
	{
		set_philo(&data->philo[n], data, n + 1);
		n++;
	}
	init_sem(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:50 by balee             #+#    #+#             */
/*   Updated: 2022/10/12 17:56:24 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	data->forks = sem_open("forks", O_CREAT, 0644, data->info[NUM_OF_PHILOS]);
	data->finish = sem_open("finish", O_CREAT, 0644, 0);
	data->eaten = sem_open("eaten", O_CREAT, 0644, 0);
	data->print = sem_open("print", O_CREAT, 0644, 1);
}

void	init_philo(t_data *data, int argc, char **argv)
{
	set_info(data, argc, argv);
	if (data->info[NUM_OF_PHILOS] == 0)
		exit_err(NOPHIL);
	if (data->info[NUM_OF_MUST_EAT] == 0)
		exit_err(NONEED);
	data->pid = (pid_t *)malloc(sizeof(pid_t) * (data->info[NUM_OF_PHILOS]));
	if (data->pid == NULL)
		exit_err(ENOMEM);
	init_sem(data);
	data->time = time_in_ms();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:45 by balee             #+#    #+#             */
/*   Updated: 2022/10/15 17:50:57 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	exit_err(int err)
{
	ft_putstr_fd("Error: ", 2);
	if (err == ENOEXEC)
		ft_putstr_fd("Exec format error\n", 2);
	else if (err == EINVAL)
		ft_putstr_fd("Invalid argument\n", 2);
	else if (err == ENOMEM)
		ft_putstr_fd("Cannot allocate memory\n", 2);
	else if (err == EAGAIN)
		ft_putstr_fd("Resource temporarily unavailable\n", 2);
	else if (err == NOPHIL)
		ft_putstr_fd("No philosopher\n", 2);
	else if (err == NONEED)
		ft_putstr_fd("No need to eat\n", 2);
	exit(err);
}

void	clean_up(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info[NUM_OF_PHILOS])
		kill(data->pid[i++], SIGINT);
	free(data->pid);
	data->pid = NULL;
	sem_close(data->forks);
	sem_close(data->finish);
	sem_close(data->print);
	sem_close(data->eaten);
	sem_unlink("forks");
	sem_unlink("finish");
	sem_unlink("eaten");
	sem_unlink("print");
	i = 0;
	while (i < data->info[NUM_OF_PHILOS])
	{
		sem_close(data->philo[i].eating);
		sem_unlink(data->philo[i].name);
		free(data->philo[i].name);
		data->philo[i++].name = NULL;
	}
	free(data->philo);
	data->philo = NULL;
}

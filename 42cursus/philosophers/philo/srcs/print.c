/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:06:08 by balee             #+#    #+#             */
/*   Updated: 2022/09/08 13:06:10 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_str(char *str, t_data *data, t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&data->print);
	time = time_in_ms() - data->time;
	if (!data->fin)
		printf("%lldms %d %s\n", time, philo->num, str);
	pthread_mutex_unlock(&data->print);
}

int	print_error(int err)
{
	ft_putstr_fd("Error: ", 2);
	if (err == ENOEXEC)
		ft_putstr_fd("Exec format error\n", 2);
	else if (err == EINVAL)
		ft_putstr_fd("Invalid argument\n", 2);
	else if (err == ENOMEM)
		ft_putstr_fd("Cannot allocate memory\n", 2);
	else if (err == EFAULT)
		ft_putstr_fd("Bad address\n", 2);
	else if (err == EDEADLK)
		ft_putstr_fd("Resource deadlock avoided\n", 2);
	else if (err == EAGAIN)
		ft_putstr_fd("Resource temporarily unavailable\n", 2);
	else if (err == NOPHIL)
		ft_putstr_fd("No philosopher\n", 2);
	return (err);
}

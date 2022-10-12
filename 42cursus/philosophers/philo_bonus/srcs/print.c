/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:06:08 by balee             #+#    #+#             */
/*   Updated: 2022/10/10 02:51:02 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_str(char *str, t_data *data, t_philo *philo)
{
	long long	time;

	sem_wait(data->print);
	time = time_in_ms() - data->time;
	printf("%lldms %d %s\n", time, philo->num, str);
	sem_post(data->print);
}

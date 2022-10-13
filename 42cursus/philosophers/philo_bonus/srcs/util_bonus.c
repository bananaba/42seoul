/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:06:14 by balee             #+#    #+#             */
/*   Updated: 2022/10/13 19:17:14 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	print_str(char *str, t_data *data, t_philo *philo)
{
	long long	time;

	sem_wait(data->print);
	time = time_in_ms() - data->time;
	printf("%lldms %d %s\n", time, philo->num, str);
	sem_post(data->print);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

long long	time_in_ms(void)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	return ((temp.tv_sec * 1000) + (temp.tv_usec / 1000));
}

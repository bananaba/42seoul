/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:36 by balee             #+#    #+#             */
/*   Updated: 2022/09/14 15:35:41 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<pthread.h>
# include	<stdio.h>
# include	<errno.h>
# include	<sys/time.h>

# define SUCCESS 0
# define NOPHIL -1
# define NONEED -2

# define NUM_OF_PHILOS 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define NUM_OF_MUST_EAT 4

typedef struct s_philo
{
	int				num;
	int				first;
	int				second;
	int				eat_cnt;
	long long		eat_time;
	struct s_data	*data;
	pthread_t		tid;
	pthread_mutex_t	eating;
}	t_philo;

typedef struct s_data
{
	int				info[5];
	int				fin;
	int				eat;
	long long		time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	finish;
}	t_data;
//util.c
size_t		ft_strlen(const char *str);
void		ft_putstr_fd(char *s, int fd);
long long	time_in_ms(void);
int			fin_num(t_data *data);
//init.c
int			init_philo(t_data *data, int argc, char **argv);
void		init_mutex(t_data *data);
int			malloc_all(t_data *data);
int			set_info(t_data *data, int argc, char **argv);
void		set_philo(t_data *data);
//philo.c
int			philo_start(t_data *data);
void		philo_eat(t_philo *philo, t_data *data);
void		check_philos(t_data *data);
void		monitoring(t_data *data);
void		*philo_routine(t_philo *philo);
//print.c
int			print_error(int err);
void		print_str(char *str, t_data *data, t_philo *philo);
//exit.c
void		free_all(t_data *data);
void		destroy_all(t_data *data);
void		clean_up(t_data *data);

#endif
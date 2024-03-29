/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:36 by balee             #+#    #+#             */
/*   Updated: 2022/10/15 17:18:26 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<pthread.h>
# include	<stdio.h>
# include	<errno.h>
# include	<sys/time.h>
# include	<signal.h>
# include	<semaphore.h>

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
	int				eat_cnt;
	long long		eat_time;
	char			*name;
	struct s_data	*data;
	sem_t			*eating;
}	t_philo;

typedef struct s_data
{
	int			info[5];
	long long	time;
	pid_t		*pid;
	sem_t		*forks;
	sem_t		*eaten;
	sem_t		*finish;
	sem_t		*print;
	sem_t		*start;
	t_philo		*philo;
}	t_data;
//util.c
size_t		ft_strlen(const char *str);
void		ft_putstr_fd(char *s, int fd);
long long	time_in_ms(void);
void		print_str(char *str, t_data *data, t_philo *philo);
//init.c
void		init_philo(t_data *data, int argc, char **argv);
void		init_sem(t_data *data);
char		*set_name(int num);
void		set_philo(t_philo *philo, t_data *data, int num);
void		set_info(t_data *data, int argc, char **argv);
//philo.c
int			philo_start(t_data *data);
void		philosopher(t_data *data, int num);
void		*monitoring(t_philo *philo);
void		eating(t_philo *philo, t_data *data);
//exit.c
void		exit_err(int err);
void		clean_up(t_data *data);

#endif

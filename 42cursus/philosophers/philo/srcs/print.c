#include "../includes/philo.h"

void	print_str(char *str, t_data *data, t_philo *philo)
{
	long long	time;

	time = time_in_ms() - data->time;
	pthread_mutex_lock(&data->print);
	if (!data->fin)
		printf("%lldms %d %s\n", time, philo->num, str);
	pthread_mutex_unlock(&data->print);
}

int	print_error(int err)
{
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
	return (err);
}

#include "../includes/philo.h"

long long	time_in_ms(void)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	return ((temp.tv_sec * 1000) + (temp.tv_usec / 1000));
}

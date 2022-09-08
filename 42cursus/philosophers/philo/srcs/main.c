#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		err;

	if (argc != 5 && argc != 6)
		return (print_error(ENOEXEC));
	err = init_philo(&data, argc, argv);
	if (err)
		return (print_error(err));
	err = philo_start(&data);
	if (err)
		return (print_error(err));
	return (SUCCESS);
}
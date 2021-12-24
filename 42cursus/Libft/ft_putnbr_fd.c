#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	if (!str)
		return ;
	ft_putstr_fd(str[index++], fd);
	free(str);
}

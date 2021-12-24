#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (!*s)
		return ;
	while (s[index])
		ft_putchar_fd(s[index++], fd);
	ft_putchar_fd('\n', fd);
}

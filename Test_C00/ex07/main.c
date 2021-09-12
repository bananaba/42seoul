#include <stdio.h>

void	ft_putnbr(int nb);

int	main(void)
{
	int nb;
	printf("number : ");
	scanf("%d", &nb);
	ft_putnbr(nb);
	return (0);
}

#include <stdio.h>
void	ft_putchar(char c);

int	main(void)
{
	char c;
	printf("출력할 문자 : ");
	scanf("%c", &c);
	ft_putchar(c);
	return (0);
}

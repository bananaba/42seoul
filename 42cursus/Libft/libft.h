#ifndef		LIBFT.H
# define	LIBHT.H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void	*content;
	struct	s_list *next;
}	t_list;

int	ft_atoi(const char *str);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char*));
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);

#endif

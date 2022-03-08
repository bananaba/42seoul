#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i)
		*((unsigned char *)b + i++) = c;
	return (b);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

typedef struct s_info
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		length;
	int		plus;
	int		space;
	int		sharp;
	char	type;
} t_info;

char	*check_info(char *str, t_info *info, va_list ap)
{
	while (*(++str))
	{
		if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd' ||
			*str == 'i' || *str == 'u' || *str == 'x' || *str == 'X' || *str == '%')
			break;
		else if (*str == '-')
			info->minus = 1;
		else if (*str == '+')
			info->plus = 1;
		else if (*str == '#')
			info->sharp = 1;
		else if (*str == ' ')
			info->space = 1;
		else if (*str == '.')
			info->prec = 1;
		else if (info->prec && (*str >= '0' && *str <= '9'))
			info->length = info->length * 10 + *str - '0';
		else if (!info->prec && !info->width && *str == '0')
			info->zero = 1;
		else if (!info->prec && (*str >= '0' && *str <= '9'))
			info->width = info->width * 10 + *str - '0';
		else if (info->prec && *str == '*' && !info->length)
			info->length = va_arg(ap, int);
		else if (!info->prec && *str == '*' && !info->width)
			info->width = va_arg(ap, int);
		else
			return (NULL);
	}
	if (!*str)
		return (NULL);
	info->type = *str;
	return (str);
}

void	print_space(int zero, int len)
{
	char	space;

	space = ' ';
	if (zero)
		space = '0';
	while (--len > 0)
		write(1, space, 1);
}

int	print_char(char c, t_info *info)
{
	if (info->minus)
	{
		write(1, c, 1);
		print_space(0, info->width - 1);
	}
	else
	{
		print_space(info->zero, info->width - 1);
		write(1, c, 1);
	}
	if (!info->width)
		return (1);
	return (info->width);
}

int	print_str(char *str, t_info *info)
{
	int	len;

	len = ft_strlen(str);
	if (info->prec && len > info->length)
		len = info->length;
	if (info->minus)
	{
		write(1, str, len);
		print_space(0, info->width - len);
	}
	else
	{
		print_space(info->zero, info->width - len);
		write(1, str, len);
	}
	if (info->width < len)
		return (len);
	return (info->width);
}

int	print_pointer(void *p, t_info *info);

int	find_figures(int n, t_info *info)
{
	int				figures;
	unsigned int	temp;

	figures = 1;
	temp = n;
	if (n < 0)
	{
		figures++;
		temp = -n;
	}
	else if (info->plus || info->space)
		figures++;
	while (temp >= 10)
	{
		figures++;
		temp /= 10;
	}
	return (figures);
}

void	print_nbr(unsigned int n)
{
	char	c;

	c = n % 10 + '0';
	if (n >= 10)
		print_nbr(n / 10);
	write(1, &c, 1);
}

void	ft_putnbr(int n, t_info *info)
{
	unsigned int	temp;

	if (n < 0)
	{
		write(1, "-", 1);
		temp = n * -1;
	}
	else
	{
		temp = n;
		if (info->plus)
			write(1, "+", 1);
		else if (info->space)
			write(1, " ", 1);
	}
	print_nbr(temp);
}

int	print_decimal(int d, t_info *info)
{
	int	len;

	len = find_figures(d, info);
	if (info->minus)
	{
		ft_putnbr(d, info);
		print_space(0, info->width - len);
	}
	else
	{
		print_space(info->zero, info->width - len);
		ft_putnbr(d, info);
	}
	if (info->width < len)
		return (len);
	return (info->width);
}
int	print_unsigned_decimal(unsigned int d, t_info *info);
int	print_hexa_decimal(unsigned int d, t_info *info);

int	print_format(va_list ap, t_info *info)
{
	if (info->type == '%')
		return (print_char('%', info));
	else if (info->type == 'c')
		return (print_char(va_arg(ap, int), info));
	else if (info->type == 's')
		return (print_str(va_arg(ap, char *), info));
	else if (info->type == 'p')
		return (print_pointer(va_arg(ap, void *), info));
	else if (info->type == 'd' || info->type == 'i')
		return (print_decimal(va_arg(ap, int), info));
	else if (info->type == 'u')
		return (print_unsigned_decimal(va_arg(ap, unsigned int), info));
	else if (info->type == 'x' || info->type == 'X')
		return (print_hexa_decimal(va_arg(ap, unsigned int), info));
}


int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_info	*info;
	int		len;

	va_start(ap, str);
	info = (t_info *)malloc(sizeof(t_info) * 1);
	if (!info)
		return (-1);
	len = 0;
	while (*str)
	{
		if (*str != '%')
			len += write(1, str, 1);
		else
		{
			ft_memset(info, 0, sizeof(t_info));
			str = check_info((char *)str, info, ap);
			if (!str)
				return (-1);
		}
		str++;
	}
	va_end(ap);
	return (len);
}

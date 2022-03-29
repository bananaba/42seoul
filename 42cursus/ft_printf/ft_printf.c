/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:28:48 by balee             #+#    #+#             */
/*   Updated: 2022/03/27 04:00:03 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_or_length(char c, t_info *info, va_list ap)
{
	if (info->prec && (c >= '0' && c <= '9'))
		info->length = info->length * 10 + c - '0';
	else if (!info->prec && !info->width && c == '0')
		info->zero = 1;
	else if (!info->prec && (c >= '0' && c <= '9'))
		info->width = info->width * 10 + c - '0';
	else if (info->prec && c == '*' && !info->length)
		info->length = va_arg(ap, int);
	else if (!info->prec && c == '*' && !info->width)
		info->width = va_arg(ap, int);
}

char	*check_info(char *str, t_info *info, va_list ap)
{
	while (*(++str))
	{
		if (*str == '-')
			info->minus = 1;
		else if (*str == '+')
			info->plus = 1;
		else if (*str == '#')
			info->sharp = 1;
		else if (*str == ' ')
			info->space = 1;
		else if (*str == '.')
			info->prec = 1;
		else if (*str == '*' || (*str >= '0' && *str <= '9'))
			width_or_length(*str, info, ap);
		else
			break ;
	}
	return (str);
}

int	print_format(va_list ap, t_info *info)
{
	if (info->type == '%')
		return (print_char('%', info));
	else if (info->type == 'c')
		return (print_char(va_arg(ap, int), info));
	else if (info->type == 's')
		return (print_str(va_arg(ap, char *), info));
	else if (info->type == 'p')
		return (print_hexa_decimal((long long)va_arg(ap, void *), info));
	else if (info->type == 'd' || info->type == 'i')
		return (print_decimal((long long)va_arg(ap, int), info));
	else if (info->type == 'u')
		return (print_decimal((long long)va_arg(ap, unsigned int), info));
	else if (info->type == 'x' || info->type == 'X')
		return (print_hexa_decimal((long long)va_arg(ap, unsigned int), info));
	return (-1);
}

int	printf_main(const char *str, va_list ap, t_info *info)
{
	int	len;
	int	temp;

	len = 0;
	while (*str)
	{
		if (*str != '%')
			len += write(1, str, 1);
		else
		{
			ft_memset(info, 0, sizeof(t_info));
			str = check_info((char *)str, info, ap);
			if (!*str)
				return (-1);
			info->type = *str;
			temp = print_format(ap, info);
			if (temp == -1)
				return (-1);
			len += temp;
		}
		str++;
	}
	return (len);
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
	len = printf_main(str, ap, info);
	free(info);
	va_end(ap);
	return (len);
}

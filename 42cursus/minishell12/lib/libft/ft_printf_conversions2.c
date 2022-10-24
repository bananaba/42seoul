/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:34:36 by snoh              #+#    #+#             */
/*   Updated: 2022/05/21 13:44:23 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"

const int	g_endsize = 30;

static void	ft_dec2hex(unsigned long long s, char *r, char *scale)
{
	unsigned long long	n;
	int					i;

	n = s;
	i = 0;
	if (!n)
		r[g_endsize - 2] = scale[0];
	while (n)
	{
		r[g_endsize - 2 - i] = scale[n % 16];
		i++;
		n = n / 16;
	}
}

static	unsigned long	ft_pt2long(void *p)
{
	void			*a;
	unsigned long	*b;

	a = p;
	b = (unsigned long *) &a;
	return (*b);
}

char	*convert_p(char *str, va_list *ap)
{
	char	*r;
	int		i;
	int		j;

	r = calloc(sizeof(char), g_endsize);
	if (r && str[1] == 'p')
	{
		ft_dec2hex(ft_pt2long(va_arg(*ap, void *)), r, "0123456789abcdef");
		i = -1;
		while (++i < g_endsize - 1 && !r[i])
			;
		j = 1;
		i--;
		while (++i < g_endsize - 1 && r[i])
			r[++j] = r[i];
		r[++j] = 0;
		r[0] = '0';
		r[1] = 'x';
	}
	return (r);
}

char	*convert_x(char *str, va_list *ap)
{
	char	*r;
	int		i;
	int		j;

	r = calloc(sizeof(char), g_endsize);
	if (r && str[1] == 'x')
	{
		ft_dec2hex((unsigned int) va_arg(*ap, int), r, "0123456789abcdef");
		i = -1;
		while (++i < g_endsize - 1 && !r[i])
			;
		j = -1;
		i--;
		while (++i < g_endsize - 1 && r[i])
			r[++j] = r[i];
		r[++j] = 0;
	}
	return (r);
}

char	*convert_large_x(char *str, va_list *ap)
{
	char	*r;
	int		i;
	int		j;

	r = calloc(sizeof(char), g_endsize);
	if (r && str[1] == 'X')
	{
		ft_dec2hex((unsigned int) va_arg(*ap, int), r, "0123456789ABCDEF");
		i = -1;
		while (++i < g_endsize - 1 && !r[i])
			;
		j = -1;
		i--;
		while (++i < g_endsize - 1 && r[i])
			r[++j] = r[i];
		r[++j] = 0;
	}
	return (r);
}

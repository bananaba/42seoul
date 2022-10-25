/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:41:00 by snoh              #+#    #+#             */
/*   Updated: 2022/05/20 15:41:44 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"

char	*convert_percent(char *str, va_list *ap)
{
	char	*r;

	r = ft_calloc(sizeof(char), 2);
	if (r && ap)
	{
		if (str[1] == '%')
		{
			r[0] = '%';
		}
	}
	return (r);
}

static void	ft_unsigneddec2str(unsigned long s, char *r, char *scale)
{
	long	n;
	int		i;

	n = s;
	i = 0;
	if (!n)
		r[28] = scale[0];
	while (n)
	{
		r[28 - i] = scale[n % 10];
		i++;
		n = n / 10;
	}
}

char	*convert_u(char *str, va_list *ap)
{
	char	*r;
	int		i;
	int		j;

	r = calloc(sizeof(char), 30);
	if (r && str[1] == 'u')
	{
		ft_unsigneddec2str(va_arg(*ap, unsigned int), r, "0123456789");
		i = -1;
		while (++i < 29 && !r[i])
			;
		j = -1;
		i--;
		while (++i < 29 && r[i])
			r[++j] = r[i];
		r[++j] = 0;
	}
	return (r);
}

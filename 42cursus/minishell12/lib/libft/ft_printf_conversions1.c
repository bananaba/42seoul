/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:41:00 by snoh              #+#    #+#             */
/*   Updated: 2022/05/21 11:19:56 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"

char	*convert_c(char *str, va_list *ap)
{
	char	*r;

	r = ft_calloc(sizeof(char), 2);
	if (r)
	{
		if (str[1] == 'c')
		{
			r[0] = va_arg(*ap, int);
		}
	}
	return (r);
}

char	*convert_s(char *str, va_list *ap)
{
	char	*r;
	char	*s;

	r = 0;
	if (str[1] == 's')
	{
		s = va_arg(*ap, char *);
		if (s)
			r = ft_strdup(s);
		else
			r = ft_strdup("(null)");
	}
	return (r);
}

char	*convert_d(char *str, va_list *ap)
{
	char	*r;

	r = 0;
	if (str[1] == 'd')
	{
		r = ft_itoa(va_arg(*ap, int));
	}
	return (r);
}

char	*convert_i(char *str, va_list *ap)
{
	char	*r;

	r = 0;
	if (str[1] == 'i')
	{
		r = ft_itoa(va_arg(*ap, int));
	}
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:28:56 by balee             #+#    #+#             */
/*   Updated: 2022/03/27 04:03:26 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(long long d, t_info *info, int zero_len, int len)
{
	if (!info->minus)
		print_space(info->zero, info->width - len);
	if (d < 0)
	{
		write(1, "-", 1);
		d = d * -1;
	}
	else if (info->plus)
		write(1, "+", 1);
	else if (info->space)
		write(1, " ", 1);
	print_space(1, zero_len);
	if (!info->prec || info->length || d)
		print_nbr((unsigned long long)d, info, 10);
	if (info->minus)
		print_space(0, info->width - len);
}

int	print_decimal(long long d, t_info *info)
{
	int	len;
	int	zero_len;

	if (info->type == 'u')
		d = (unsigned int)d;
	if (d < 0)
	{
		info->type = '-';
		len = find_figures(-d, info, 10, &zero_len);
		len++;
	}
	else
	{
		len = find_figures(d, info, 10, &zero_len);
		if (info->plus || info->space)
			len++;
	}
	print_int(d, info, zero_len, len);
	if (info->width < len)
		return (len);
	return (info->width);
}

void	print_hexa(long long d, t_info *info, int zero_len)
{
	if (info->type == 'p')
		write(1, "0x", 2);
	else if (info->sharp && info->type != 'p' && d)
	{
		write(1, "0", 1);
		write(1, &info->type, 1);
	}
	print_space(1, zero_len);
	if (!info->prec || info->length || d)
		print_nbr((unsigned long long)d, info, 16);
}

int	print_hexa_decimal(long long d, t_info *info)
{
	int	len;
	int	zero_len;

	if (info->type == 'x' || info->type == 'X')
		d = (unsigned int)d;
	len = find_figures(d, info, 16, &zero_len);
	if ((info->sharp && d) || info->type == 'p')
		len += 2;
	if (info->minus)
	{
		print_hexa(d, info, zero_len);
		print_space(0, info->width - len);
	}
	else
	{
		print_space(info->zero, info->width - len);
		print_hexa(d, info, zero_len);
	}
	if (len > info->width && len > info->length)
		return (len);
	else if (info->length > info->width)
		return (info->length);
	return (info->width);
}

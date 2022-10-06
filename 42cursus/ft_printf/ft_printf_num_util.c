/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:28:50 by balee             #+#    #+#             */
/*   Updated: 2022/03/27 03:55:51 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_zero_len(t_info *info, int figures)
{
	int	zero_len;

	if (info->zero && info->width && !info->prec)
	{
		zero_len = info->width - figures - 1;
		if (info->type != '-')
			zero_len--;
	}
	else
	{
		zero_len = info->length - figures;
		info->zero = 0;
	}
	return (zero_len);
}

int	find_figures(unsigned long long n, t_info *info, int d, int *zero_len)
{
	int			figures;

	figures = 1;
	while (n >= (unsigned long long)d)
	{
		figures++;
		n /= d;
	}
	*zero_len = find_zero_len(info, figures);
	if (*zero_len > 0)
		figures += *zero_len;
	if (info->prec && !info->length && !n)
	{
		*zero_len = 0;
		return (0);
	}
	return (figures);
}

void	print_nbr(unsigned long long n, t_info *info, int d)
{
	int		c;
	char	*num;

	num = "0123456789abcdef";
	if (info->type == 'X')
		num = "0123456789ABCDEF";
	c = n % d;
	if (n >= (unsigned long long)d)
		print_nbr(n / d, info, d);
	write(1, &num[c], 1);
}

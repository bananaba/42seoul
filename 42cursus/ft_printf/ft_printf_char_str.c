/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:28:41 by balee             #+#    #+#             */
/*   Updated: 2022/03/23 09:47:02 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_info *info)
{
	if (info->minus)
	{
		write(1, &c, 1);
		print_space(0, info->width - 1);
	}
	else
	{
		print_space(info->zero, info->width - 1);
		write(1, &c, 1);
	}
	if (!info->width)
		return (1);
	return (info->width);
}

int	print_str(char *str, t_info *info)
{
	int	len;

	if (!str)
		str = "(null)";
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

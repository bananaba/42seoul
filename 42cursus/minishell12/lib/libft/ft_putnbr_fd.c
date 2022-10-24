/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:42:31 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 16:59:50 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long	tf_abs(long long a)
{
	if (a > 0)
	{
		return (a);
	}
	else
	{
		return (-a);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	a;

	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		a = tf_abs(n);
		if (n < 0)
			ft_putchar_fd('-', fd);
		i = 1000000000;
		while (!(a / i))
			i /= 10;
		while (i)
		{
			ft_putchar_fd(a / i % 10 + '0', fd);
			i /= 10;
		}
	}
}

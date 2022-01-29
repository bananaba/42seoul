/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:32:11 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:32:13 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;
	char			c;

	if (n < 0)
	{
		write(fd, "-", 1);
		temp = n * -1;
	}
	else
		temp = n;
	c = temp % 10 + '0';
	if (temp >= 10)
		ft_putnbr_fd(temp / 10, fd);
	write(fd, &c, 1);
}

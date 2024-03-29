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

void	print_nbr(unsigned int n, int fd)
{
	char	c;

	c = n % 10 + '0';
	if (n >= 10)
		print_nbr(n / 10, fd);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		temp = n * -1;
	}
	else
		temp = n;
	print_nbr(temp, fd);
}

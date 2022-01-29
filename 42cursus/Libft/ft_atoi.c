/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:45 by balee             #+#    #+#             */
/*   Updated: 2021/11/23 16:26:49 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			i;
	int			status;
	long long	num;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	status = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			status = -1;
		i++;
	}
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - '0';
		if (num * status > 2147483647)
			return (-1);
		else if (num * status < -2147483648)
			return (0);
	}
	return ((int)(num * status));
}

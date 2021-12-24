/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:55 by balee             #+#    #+#             */
/*   Updated: 2021/11/23 16:30:06 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_figures(int n)
{
	int				figures;
	unsigned int	temp;

	figures = 0;
	temp = n;
	if (n <= 0)
	{
		figures++;
		temp = -n;
	}
	while (temp)
	{
		figures++;
		temp /= 10;
	}
	return (figures);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				figures;
	unsigned int	temp;

	figures = find_figures(n);
	str = (char *)malloc(sizeof(char) * (figures + 1));
	if (!str)
		retrun (0);
	str[figures--] = 0;
	temp = n;
	if (n < 0)
	{
		str[0] = '-';
		temp = -n;
	}
	while (figures >= 0 )
	{
		str[figures--] = temp % 10 + '0';
		temp /= 10;
		if (!temp)
			figures--;
	}
	return (str);
}

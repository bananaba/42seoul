/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:04:19 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 16:51:15 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *str, int ch)
{
	int		n;

	n = -1;
	while (str[++n])
	{
		if (str[n] == ch % 256)
			return ((char *) str + n);
	}
	if (str[n] == ch % 256)
		return ((char *) str + n);
	return (0);
}

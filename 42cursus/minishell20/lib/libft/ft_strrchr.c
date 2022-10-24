/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:04:54 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 16:51:31 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		n;
	char	*r;

	r = 0;
	n = -1;
	while (str[++n])
	{
		if (*(str + n) == ch % 256)
			r = (char *) str + n;
	}
	if (*(str + n) == ch % 256)
		r = (char *) str + n;
	return (r);
}

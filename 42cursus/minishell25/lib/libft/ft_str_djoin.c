/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_djoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:34:05 by snoh              #+#    #+#             */
/*   Updated: 2022/05/20 15:37:12 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_str_djoin(char **s1, char *s2, int len2)
{
	char	*r;
	int		len1;
	int		n;

	len1 = ft_strlen(*s1);
	r = ft_calloc(sizeof(char), len1 + len2 + 1);
	if (r)
	{
		n = -1;
		while (++n < len1)
			r[n] = (*s1)[n];
		while (++n < len1 + len2 + 1)
			r[n - 1] = s2[n - len1 - 1];
		r[n - 1] = 0;
	}
	if (*s1)
		free(*s1);
	*s1 = r;
}

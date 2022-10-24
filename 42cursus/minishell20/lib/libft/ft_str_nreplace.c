/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_nreplace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:34:05 by snoh              #+#    #+#             */
/*   Updated: 2022/05/20 15:35:35 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_str_nreplace(char **s1, char *s2, int len2)
{
	char	*r;
	int		n;

	r = ft_calloc(sizeof(char), len2 + 1);
	if (r)
	{
		n = -1;
		while (++n < len2)
			r[n] = (s2)[n];
		r[n] = 0;
	}
	if (*s1)
		free(*s1);
	*s1 = r;
}

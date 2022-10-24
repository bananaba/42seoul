/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:39:24 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 13:39:51 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	i;
	unsigned int	len;

	if (!s || !f)
		return (0);
	i = -1;
	len = ft_strlen(s);
	r = ft_calloc(sizeof(char), len + 1);
	if (r)
	{
		while (++i < len)
		{
			r[i] = f(i, s[i]);
		}
		r[i] = 0;
	}
	return (r);
}

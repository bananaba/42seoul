/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:33:34 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 16:49:10 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*subfunction*/
static long long	min(unsigned long long a, unsigned long long b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	long long	l;

	if (start > ft_strlen(s) + 2)
		return (ft_strdup(""));
	l = min(len, ft_strlen(&s[start]));
	//ft_printf("debug5 : %i\n", runnable->text, cut_start, i-cut_start);
	r = ft_calloc(sizeof(char), l + 1);
	if (r)
	{
		ft_strlcpy(r, &s[start], l + 1);
	}
	return (r);
}

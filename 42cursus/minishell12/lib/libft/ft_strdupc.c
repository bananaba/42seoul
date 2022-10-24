/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:34:05 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 13:37:48 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdupc(char s1, char const *s2)
{
	char	*r;

	r = ft_calloc(sizeof(char), 1 + ft_strlen(s2) + 1);
	if (r)
	{
		ft_strlcpy(&(r[1]), s2, ft_strlen(s2) + 1);
		r[0] = s1;
	}
	return (r);
}

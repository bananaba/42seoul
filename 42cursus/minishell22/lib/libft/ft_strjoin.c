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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;

	r = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (r)
	{
		ft_strlcpy(r, s1, ft_strlen(s1) + 1);
		ft_strlcat(r, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:55 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 12:24:53 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(const char *s1)
{
	char	*r;

	r = ft_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (r)
		ft_strlcpy(r, s1, ft_strlen(s1) + 1);
	return (r);
}

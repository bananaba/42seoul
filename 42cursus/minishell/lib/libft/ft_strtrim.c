/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:38:20 by snoh              #+#    #+#             */
/*   Updated: 2022/01/05 14:51:35 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;
	char	*r;

	a = 0;
	b = 0;
	while (s1[a] && ft_strchr(set, s1[a]))
		a++;
	b = ft_strlen(s1) - 1;
	while (b >= 0 && s1[b] && ft_strchr(set, s1[b]))
		b--;
	if (b - a < 1)
		return (ft_strdup(""));
	r = ft_substr(s1, a, b - a + 1);
	return (r);
}

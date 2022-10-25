/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:03:29 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 03:21:27 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen_s(const char *str, char *set)
{
	size_t	n;

	n = 0;
	while (str[n] && ft_strchr(set, str[n]) == 0)
		n++;
	return (n);
}

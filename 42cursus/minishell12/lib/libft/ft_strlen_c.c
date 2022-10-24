/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:03:29 by snoh              #+#    #+#             */
/*   Updated: 2022/10/02 09:24:56 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen_c(const char *str, char c)
{
	size_t	n;

	n = 0;
	while (str[n] &&  str[n] != c)
		n++;
	return (n);
}

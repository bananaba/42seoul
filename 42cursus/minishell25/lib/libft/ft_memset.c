/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:25:19 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 12:59:19 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			a;
	unsigned char	d;
	unsigned char	*e;

	a = 0;
	e = (unsigned char *) b;
	d = (unsigned char) c;
	while (a < len)
	{
		e[a] = d;
		a++;
	}
	return (b);
}

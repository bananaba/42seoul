/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:17:49 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 12:18:50 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isalnum(int n)
{
	if ('a' <= n && n <= 'z')
		return (1);
	else if ('A' <= n && n <= 'Z')
		return (1);
	else if ('0' <= n && n <= '9')
		return (1);
	else
		return (0);
}

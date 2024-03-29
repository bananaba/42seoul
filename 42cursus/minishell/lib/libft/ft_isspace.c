/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:20:30 by snoh              #+#    #+#             */
/*   Updated: 2022/09/25 04:53:41 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isspace(int n)
{
	if (n == 32 || n == 20 || (9 <= n && n <= 13))
		return (1);
	else
		return (0);
}

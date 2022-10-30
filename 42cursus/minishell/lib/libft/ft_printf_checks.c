/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:41:00 by snoh              #+#    #+#             */
/*   Updated: 2022/05/20 16:18:23 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"

int	ft_printf_lstcheck(t_list *lst)
{
	t_list	*p;

	p = lst;
	while (p)
	{
		if (p->content)
			p = p->next;
		else
			return (0);
	}
	return (1);
}

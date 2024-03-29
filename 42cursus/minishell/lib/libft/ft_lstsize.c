/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:48:42 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 15:48:14 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*p;

	i = 0;
	p = lst;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

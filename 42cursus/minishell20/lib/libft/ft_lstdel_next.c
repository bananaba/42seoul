/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:53:04 by snoh              #+#    #+#             */
/*   Updated: 2022/10/24 22:18:54 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lstdel_next(t_list *lst, void (*del)(void *))
{
	t_list *next;
	
	next = lst->next;

	if (next)
	{
		lst->next = next->next;
		ft_lstdelone(next, del);
	}
}

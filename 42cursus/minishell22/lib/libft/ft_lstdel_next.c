/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:53:04 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 03:20:18 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lstdel_next(t_list *lst, void (*del)(void *))
{
	t_list	*next;

	next = lst->next;
	if (next)
	{
		lst->next = next->next;
		ft_lstdelone(next, del);
	}
}

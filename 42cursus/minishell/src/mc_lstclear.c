/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 06:34:07 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmc.h"

void	mc_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*n;

	p = *lst;
	while (p)
	{
		n = p->next;
		mc_lstdelone(p, del);
		p = n;
	}
	*lst = 0;
}

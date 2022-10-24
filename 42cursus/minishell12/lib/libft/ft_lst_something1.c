/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_something1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:04 by snoh              #+#    #+#             */
/*   Updated: 2022/10/02 11:40:40 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list *ft_lstnth(t_list *p, int index)
{
	int i = 0;

	while(p && i < index)
	{
		p = p->next;
		i++;
	}
	return (p);
}

void *ft_lstadd_next(t_list *node, t_list *new)
{
	//t_list *temp;

	if (node == 0 || new == 0 || new->next != 0)
		return (0);

	new -> next = node -> next;
	node -> next = new;

	return (new->next);
}


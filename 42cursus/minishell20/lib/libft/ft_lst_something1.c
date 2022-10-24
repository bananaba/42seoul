/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_something1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:22:04 by snoh              #+#    #+#             */
/*   Updated: 2022/10/25 02:01:48 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list *ft_lstnth(t_list *p, int index)
{
	int i;

	i = 0;
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

t_list *ft_lstpop_nth(t_list *p, int index)
{
	int i;
	t_list *r;

	i = 0;
	r = 0;
	while(p && i < index - 1)
	{
		p = p->next;
		i++;
	}

	if (i == index - 1 &&  p->next)
	{
		r = p->next;
		p->next = p->next->next;
		r->next = 0;
	}

	return (r);
}

t_list *ft_lstpop_nth_p(t_list **lst, int index)
{
	int i;
	t_list *r;
	t_list *p;

	i = 0;
	r = 0;
	p = *lst;
	
	if (index == 0)
	{
		r = *lst;
		*lst = (*lst)->next;
		r->next = 0;
		return (r);
	}
	while(p && i < index - 1)
	{
		p = p->next;
		i++;
	}
	if (i == index - 1 &&  p->next)
	{
		r = p->next;
		p->next = p->next->next;
		r->next = 0;
	}
	return (r);
}
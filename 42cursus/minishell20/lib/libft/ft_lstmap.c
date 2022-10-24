/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:54:54 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 14:01:12 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*s;
	t_list	*r;
	int		i;

	r = 0;
	i = -1;
	p = lst;
	while (p)
	{
		s = ft_lstnew(f(p->content));
		if (s)
		{
			if (++i == 0)
				r = s;
			else
				ft_lstadd_back(&r, s);
			p = p->next;
		}
		else
			ft_lstclear(&r, del);
	}
	return (r);
}

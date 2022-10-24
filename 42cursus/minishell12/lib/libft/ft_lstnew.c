/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:45:28 by snoh              #+#    #+#             */
/*   Updated: 2022/01/03 13:45:43 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*r;

	r = ft_calloc(sizeof(t_list), 1);
	if (r)
	{
		r->content = content;
		r->next = 0;
	}
	return (r);
}

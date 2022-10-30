/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 06:34:14 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmc.h"

t_list	*mc_lstnew(void *content)
{
	t_list	*r;

	r = mc_calloc(sizeof(t_list), 1);
	if (r)
	{
		r->content = content;
		r->next = 0;
	}
	return (r);
}

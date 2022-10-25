/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_assets2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:26:23 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 06:39:12 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**strlist_2_splited_fast(t_list **list)
{
	t_mbox	mbox;
	t_list	*p;
	int		i;
	char	**r;

	if (!list)
		return (0);
	mbox.cur = 0;
	r = ft_calloc(sizeof(char *), ft_lstsize(*list) + 1);
	if (collector(&mbox, r) == 0)
		return (0);
	p = *list;
	i = 0;
	while (p)
	{
		r[i++] = (p->content);
		p->content = 0;
		p = p->next;
	}
	r[i] = 0;
	ft_lstclear(list, free);
	return (r);
}

int	int_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	int_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	ft_is_assign(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_isalpha(str[i]) || str[i] == '_')
	{
		while (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		if (str[i] == '=')
			return (1);
	}
	else
	{
		return (0);
	}
	return (0);
}

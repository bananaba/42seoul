/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_assets1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:26:23 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 06:38:58 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	splited_2_strlist(t_list **list, char **splited)
{
	t_mbox	mbox;
	t_list	*new_node;
	int		cnt;

	cnt = 0;
	mbox.cur = 0;
	*list = 0;
	while (splited[cnt])
	{
		new_node = ft_lstnew(splited[cnt]);
		if (collector(&mbox, new_node) == 0)
		{
			*list = 0;
			return (1);
		}
		collector(&mbox, new_node->content);
		ft_lstadd_back(list, new_node);
		cnt++;
	}
	return (0);
}

int	splited_2dup_strlist(t_list **list, char **splited)
{
	t_mbox	mbox;
	t_list	*new_node;
	int		cnt;

	cnt = 0;
	mbox.cur = 0;
	*list = 0;
	while (splited[cnt])
	{
		new_node = ft_lstnew(ft_strdup(splited[cnt]));
		if (collector(&mbox, new_node) == 0)
		{
			*list = 0;
			return (1);
		}
		collector(&mbox, new_node->content);
		ft_lstadd_back(list, new_node);
		cnt++;
	}
	return (0);
}

char	**strlist_2_splited(t_list **list)
{
	t_mbox	mbox;
	t_list	*p;
	int		i;
	char	**r;

	mbox.cur = 0;
	if (!list)
		return (0);
	r = ft_calloc(sizeof(char *), ft_lstsize(*list) + 1);
	if (collector(&mbox, r) == 0)
		return (0);
	p = *list;
	i = 0;
	while (p)
	{
		r[i] = ft_strdup(p->content);
		if (collector(&mbox, r[i++]) == 0)
			return (0);
		p = p->next;
	}
	r[i] = 0;
	return (r);
}

void	do_nothing(void *p)
{
	p = 0;
	free(p);
	return ;
}

void	**linkedlist_2_array(t_list **lst)
{
	void	**r;
	int		size;
	int		i;

	size = ft_lstsize(*lst);
	r = 0;
	if (0 < size)
	{
		r = ft_calloc(sizeof(void *), size + 1);
		if (r)
		{
			i = 0;
			while (ft_lstnth(*lst, i))
			{
				r[i] = ft_lstnth(*lst, i)->content;
				i++;
			}
			r[size] = 0;
		}
		ft_lstclear(lst, do_nothing);
	}
	return (r);
}

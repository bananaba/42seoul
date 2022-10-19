/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:27:58 by balee             #+#    #+#             */
/*   Updated: 2022/10/19 20:57:27 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

t_list	*new_list(char *arr)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	ft_bzero(temp, sizeof(t_list));
	temp->str = ft_strdup(arr);
	return (temp);
}

t_list	*array_to_list(char *arr[])
{
	int		i;
	t_list	*temp;
	t_list	*p;

	i = 1;
	temp = new_list(arr[0]);
	p = temp;
	while (arr[i])
	{
		p->next = new_list(arr[i]);
		p = p->next;
		i++;
	}
	return (temp);
}

char	**list_to_array(t_list *lst)
{
	int		i;
	char	**arr;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	arr = (char **)malloc(sizeof(char *) * (i + 1));
	ft_bzero(arr, sizeof(arr));
	i = 0;
	temp = lst;
	while (temp)
	{
		arr[i++] = ft_strdup(temp->str);
		temp = temp->next;
	}
	return (arr);
}

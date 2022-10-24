/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:26 by balee             #+#    #+#             */
/*   Updated: 2022/10/24 19:54:27 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env(t_list *envp, char **str)
{
	char	*temp;
	t_list	*lst;

	lst = envp;
	temp = ft_strjoin(str[0], "=");
	while (lst)
	{
		if (ft_strncmp(lst->content, temp, ft_strlen(temp)) == 0)
		{
			free(lst->content);
			lst->content = ft_strjoin(temp, str[1]);
			free(temp);
			return ;
		}
		lst = lst->next;
	}
	lst = ft_lstlast(envp);
	lst->next = (t_list *)malloc(sizeof(t_list));
	lst->next->content = ft_strjoin(temp, str[1]);
	free(temp);
	lst->next->next = NULL;
}

t_list	*sort_env(t_list *envp)
{
	t_list	*sorted;
	t_list	*temp1;
	t_list	*temp2;

	sorted = (t_list *)malloc(sizeof(t_list));
	sorted->next = ft_lstnew(ft_strdup(envp->content));
	envp = envp->next;
	while (envp)
	{
		temp1 = sorted;
		while (ft_strncmp(temp1->next->content, envp->content,
				ft_strlen(temp1->next->content) < 0))
			temp1 = temp1->next;
		temp2 = ft_lstnew(ft_strdup(envp->content));
		temp2->next = temp1->next;
		temp1->next = temp2;
		envp = envp->next;
	}
	return (sorted);
}

void	destroy_list(t_list *list)
{
	if (list->content)
		free(list->content);
	free(list);
}

void	print_env(t_list *envp, int **pipes)
{
	t_list	*sorted;
	t_list	*temp1;
	t_list	*temp2;
	int		i;

	sorted = sort_env(envp);
	temp1 = sorted->next;
	while (temp1)
	{
		i = 0;
		ft_putstr_fd("declare -x ", pipes[1][1]);
		while (((char *)temp1->content)[i])
		{
			ft_putchar_fd(((char *)temp1->content)[i], pipes[1][1]);
			if (((char *)temp1->content)[i++] == '=')
				ft_putchar_fd('"', pipes[1][1]);
			if (((char *)temp1->content)[i] == 0
				&& ft_strchr(temp1->content, '='))
				ft_putchar_fd('"', pipes[1][1]);
		}
		ft_putchar_fd('\n', pipes[1][1]);
	}
	ft_lstclear(sorted, destroy_list);
}

int	ft_export(t_mp *mp, char **argv, int **pipes)
{
	int		i;
	char	**str;
	t_list	*envp;

	i = -1;
	envp = mp->envp;
	if (*argv == NULL)
		print_env(envp, pipes);
	else
	{
		while (argv[++i])
		{
			if (ft_strchr(argv[i], '='))
			{
				str = ft_split(argv[i], '=');
				add_env(envp, str);
				free_double_pointer(&str);
			}
		}
	}
	return (errno);
}

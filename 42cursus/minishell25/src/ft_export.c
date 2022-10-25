/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:26 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 04:53:22 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env(t_list *envp, char **str)
{
	char	*temp;
	t_list	*lst;

	lst = envp;
	temp = mc_strjoin(str[0], "=");
	while (lst)
	{
		if (ft_strncmp(lst->content, temp, ft_strlen(temp)) == 0)
		{
			mc_free(lst->content);
			lst->content = mc_strjoin(temp, str[1]);
			mc_free(temp);
			return ;
		}
		lst = lst->next;
	}
	lst = ft_lstlast(envp);
	lst->next = mc_lstnew(mc_strjoin(temp, str[1]));
	mc_free(temp);
}

t_list	*sort_env(t_list *envp)
{
	t_list	*sorted;
	t_list	*temp1;
	t_list	*temp2;

	sorted = (t_list *)mc_malloc(sizeof(t_list));
	sorted->next = mc_lstnew(mc_strdup(envp->content));
	envp = envp->next;
	while (envp)
	{
		temp1 = sorted;
		while (temp1->next && ft_strncmp(temp1->next->content, envp->content,
				ft_strlen(temp1->next->content)) < 0)
			temp1 = temp1->next;
		if (temp1->next == NULL)
			temp1->next = mc_lstnew(mc_strdup(envp->content));
		else
		{
			temp2 = mc_lstnew(mc_strdup(envp->content));
			temp2->next = temp1->next;
			temp1->next = temp2;
		}
		envp = envp->next;
	}
	return (sorted);
}

void	print_env(t_list *envp, int **pipes)
{
	t_list	*sorted;
	t_list	*temp1;
	int		i;

	sorted = sort_env(envp);
	temp1 = sorted->next;
	while (temp1)
	{
		i = -1;
		ft_putstr_fd("declare -x ", pipes[1][1]);
		while (((char *)temp1->content)[++i])
		{
			ft_putchar_fd(((char *)temp1->content)[i], pipes[1][1]);
			if (((char *)temp1->content)[i] == '=')
				ft_putchar_fd('"', pipes[1][1]);
			if (((char *)temp1->content)[i + 1] == 0
				&& ft_strchr(temp1->content, '='))
				ft_putchar_fd('"', pipes[1][1]);
		}
		ft_putchar_fd('\n', pipes[1][1]);
		temp1 = temp1->next;
	}
	mc_lstclear(&sorted->next, mc_free);
	mc_free(sorted);
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
				str = mc_split(argv[i], '=');
				add_env(envp, str);
				str = mc_split_free(str);
			}
		}
	}
	return (errno);
}

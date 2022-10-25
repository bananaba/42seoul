/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:11 by balee             #+#    #+#             */
/*   Updated: 2022/10/25 20:59:12 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lst_to_arr(t_list *lst)
{
	char	**arr;
	int		i;
	t_list	*temp;

	arr = (char **)malloc(sizeof(char *) * (ft_lstsize(lst)+ 1));
	i = 0;
	temp = lst;
	while (temp)
	{
		arr[i++] = ft_strdup(temp->content);
		temp = temp->next;
	}
	arr[i] = NULL;
	return (arr);
}

char	*find_value(t_mp *mp, char *target)
{
	char	*value;
	t_list	*envp;

	envp = mp->envp;
	value = NULL;
	while (envp != NULL)
	{
		if (ft_strncmp(envp->content, target, ft_strlen(target)) == 0)
			value = ft_strdup(&envp->content[ft_strlen(target)]);
		envp = envp->next;
	}
	return (value);
}

void	print_errno(int err, char **argv)
{
	if (err == 0)
		return ;
	ft_putstr_fd("\nError: ", 2);
	ft_putstr_fd(argv[0], 2);
	ft_putstr_fd(": ", 2);
	if (argv[1])
	{
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": ", 2);
	}
	if (err == 127)
		ft_putstr_fd("command not found", 2);
	else if (err == 255)
		ft_putstr_fd("numeric argument required", 2);
	else if (err == -1)
		ft_putstr_fd("too many arguments", 2);
	else
		ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
}

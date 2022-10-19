/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:56:32 by balee             #+#    #+#             */
/*   Updated: 2022/10/19 19:21:02 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

typedef struct s_envp
{
	char			*str;
	struct s_envp	*next;
}	t_envp;

t_envp	*new_envp(char *envp)
{
	t_envp	*temp;

	temp = (t_envp *)malloc(sizeof(t_envp));
	temp->next = NULL;
	if (envp)
		temp->str = ft_strdup(envp);
	else
		temp->str = NULL;
	return (temp);
}

void	add_new(t_envp *sorted, t_envp *new)
{
	t_envp	*temp;

	temp = sorted;
	while (temp->next != NULL
		&& ft_strncmp(temp->next->str, new->str, ft_strlen(new->str)) < 0)
		temp = temp->next;
	new->next = temp->next;
	temp->next = new;
}

t_envp	*sort_envp(char *envp[])
{
	int		i;
	t_envp	*sorted;

	i = 0;
	sorted = new_envp(NULL);
	while (envp[i + 1])
	{
		add_new(sorted, new_envp(envp[i++]));
	}
	return (sorted);
}

void	print_all_envp(t_envp *sorted)
{
	t_envp	*temp;

	temp = sorted;
	while (temp->next)
	{
		temp = temp->next;
		printf("%s\n", temp->str);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_envp	*sorted;
	t_envp	*temp;

	sorted = sort_envp(envp);
	print_all_envp(sorted);
	while (sorted)
	{
		temp = sorted->next;
		free(sorted);
		sorted = temp;
	}
	return (errno);
}

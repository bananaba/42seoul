/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_const_dest2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:30:07 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 06:39:49 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct s_runnable	*new_runnable_with_size(int size)
{
	t_r	*r;
	t_e	**excutable_list;

	r = ft_calloc(sizeof(t_r), 1);
	excutable_list = ft_calloc(sizeof(t_e *), size + 1);
	if (r && excutable_list)
	{
		r->state = 0;
		r->text = 0;
		r->num_of_excutables = size;
		r->excutables = excutable_list;
		excutable_list[size] = 0;
	}
	else
	{
		free(r);
		free(excutable_list);
	}
	return (r);
}

void	print_strlist(t_list *lst, char *name)
{
	int		i;
	t_list	*p;

	ft_printf("print_strlist : %s \n", name);
	p = lst;
	i = 0;
	while (p)
	{
		ft_printf("\t%s[%d]=%s\n", name, i, p->content);
		i++;
		p = p->next;
	}
	ft_printf("end of print_strlist : %s \n", name);
}

void	print_splited(char **splited, char *name)
{
	int	i;

	ft_printf("print_splited : %s \n", name);
	i = -1;
	if (splited)
	{
		while (splited[++i])
		{
			ft_printf("\t%s[%d]=%s\n", name, i, splited[i]);
		}
	}
	else
	{
		ft_printf("\t is void pointer\n");
	}
	ft_printf("end of print_splited : %s \n", name);
}

void	print_excutable(t_e *excutable, char *name)
{
	ft_printf("print_excutable : %s \n", name);
	if (excutable == 0)
	{
		ft_printf("excutable %s is void \n", name);
		return ;
	}
	print_splited(excutable->argv, "argv");
	print_token_list(excutable->redirections, "redirections");
	ft_printf("\tstate                : %i \n", excutable->state);
	ft_printf("end of print_excutable : %s \n", name);
}

void	*ft_split_free(char **splited)
{
	int	i;

	i = -1;
	if (splited)
	{
		while (splited[++i])
		{
			free(splited[i]);
		}
		free (splited);
	}
	return (0);
}

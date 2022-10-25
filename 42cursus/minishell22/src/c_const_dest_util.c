/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_const_dest_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:30:07 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 02:34:24 by balee            ###   ########.fr       */
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

void	print_strlist(t_list *lst, char * name)
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
	//print_strlist(excutable->envp, "envp");
	print_token_list(excutable->redirections, "redirections");
	ft_printf("\tstate                : %i \n", excutable->state);
	ft_printf("end of print_excutable : %s \n", name);
}

void	print_runnable(t_r *runnable, char *name)
{
	int	i;

	ft_printf("\n");
	ft_printf("\n");
	ft_printf("print_runnable : %s \n", name);
	if (runnable == 0)
	{
		ft_printf("runnable %s is void \n", name);
		return ;
	}	
	ft_printf("\ttext                    : %s \n", runnable->text);
	ft_printf("\tnum_of_excutables       : %i \n", runnable->num_of_excutables);
	i = -1;
	if (runnable->excutables)
	{
		while (runnable->excutables[++i])
		{
			print_excutable(runnable->excutables[i], " ");
			ft_printf("\n");
			ft_printf("\n");
		}
	}
	ft_printf("\tstate                   : %i \n", runnable->state);
	ft_printf("end of print_runnable : %s \n", name);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
}
/*
void print_excutable(t_e *excutable, char *name)
{
	ft_printf("print_excutable : %s \n", name);
	if (excutable == 0)
	{
		ft_printf("excutable %s is void \n", name);
		return;
	}

	ft_printf("\ttext                    : %s \n", excutable->text);
	ft_printf("\texcutable_path          : %s \n", excutable->excutable_path);
	ft_printf("\tredirections            : %s \n", excutable->redirections);


	print_splited(excutable->argv, "argv");
	print_strlist(*excutable->envp, "envp");

	ft_printf("\tnum_of_input_redirects  : %i \n", excutable->num_of_input_redirects);
	ft_printf("\tnum_of_output_redirects : %i \n", excutable->num_of_output_redirects);

	ft_printf("\tinput_redirect_flag  : %i \n", excutable->input_redirect_flag);
	print_splited(excutable->input_redirect, "input_redirects");

	ft_printf("\toutput_redirect_flag : %i \n", excutable->output_redirect_flag);
	print_splited(excutable->output_redirect, "output_redirects");

	ft_printf("\tstate                : %i \n", excutable->state);


	ft_printf("end of print_excutable : %s \n", name);
}


void print_runnable(t_r *runnable, char* name)
{
	int i;

	ft_printf("\n");
	ft_printf("\n");
	ft_printf("print_runnable : %s \n", name);
	if (runnable == 0)
	{
		ft_printf("runnable %s is void \n", name);
		return;
	}	

	ft_printf("\ttext                    : %s \n", runnable->text);
	ft_printf("\tnum_of_excutables       : %i \n", runnable->num_of_excutables);

	i = -1;
	if (runnable->excutables)
	{
		while(runnable->excutables[++i])
			print_excutable(runnable->excutables[i], " ");
	}

	ft_printf("\tstate                   : %i \n", runnable->state);
	ft_printf("end of print_runnable : %s \n", name);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");

}

*/

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

/*
char *ft_split_join(char **splited)//미완성
{
	int i;
	int len;
	char *r;

	i = -1;
	len = 0;
	r = 0;
	if (splited)
	{
		while (splited[++i])
		{
			len += ft_strlen(splited[i]);
		}
		ft_calloc(sizeof(char),len + 1);
		while (splited[++i])
		{
			len += ft_strlen(splited[i]);
		}
	}
	return (r);
}
*/
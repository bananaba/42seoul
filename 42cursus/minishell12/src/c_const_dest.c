#include "minishell.h"

void *destruct_excutable(t_e *excutable)
{
	free(excutable->text);
	excutable->text = 0;
	free(excutable->excutable_path);
	excutable->excutable_path = 0;
	free(excutable->redirections);
	excutable->redirections = 0;
	excutable->argv = 0;
	excutable->envp = 0;
	ft_split_free(excutable->input_redirect);
	excutable->input_redirect = 0;
	ft_split_free(excutable->output_redirect);
	excutable->output_redirect = 0;
	free(excutable);
	return (0);
}


void *destruct_runnable(t_r *runnable)
{
	int i;
	free(runnable->text);
	runnable->text = 0;

	i = -1;
	while(runnable->excutables && runnable->excutables[++i])
		destruct_excutable(runnable->excutables[i]);
	free(runnable->excutables);
	runnable->excutables = 0;
	free(runnable);
	return (0);
}

void *destruct_command(t_c *command)
{
	int i;

	i = -1;
	free(command->text);
	command->text = 0;
	while(command->runnables && command->runnables[++i])
		destruct_runnable(command->runnables[i]);
	free(command->runnables);
	command->runnables = 0;
	free(command);
	return (0);
}


void *destruct_minishell_program(t_mp *minishell_program)
{
	minishell_program->initial_argv = 0;
	minishell_program->initial_envp = 0;

	ft_lstclear(&minishell_program->envp, free);
	destruct_command(minishell_program->command);
	minishell_program->command = 0;
	return (0);
}

/*
void initialize_excutable(t_e *excutable)
{
	excutable->text = 0;
	excutable->excutable_path = 0;
	excutable->redirections = 0;

	excutable->argv = 0;
	excutable->envp = 0;

	excutable->num_of_input_redirects = 0;
	excutable->num_of_output_redirects = 0;

	excutable->input_redirect_flag = 0;
	excutable->input_redirect = 0;

	excutable->output_redirect_flag = 0;
	excutable->output_redirect = 0;

	state = 0;
}
*/


void print_strlist(t_list *lst, char * name)
{
	int		i;
	t_list	*p;

	ft_printf("print_strlist : %s \n", name);
	p = lst;
	i = 0;
	while(p)
	{
		ft_printf("\t%s[%d]=%s\n", name, i, p->content);
		i++;
		p = p->next;
	}
	ft_printf("end of print_strlist : %s \n", name);


}

void print_splited(char **splited, char *name)
{
	int i;

	ft_printf("print_splited : %s \n", name);
	i = -1;
	if (splited)
	{
		while(splited[++i])
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






void *ft_split_free(char **splited)
{
	int i;

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


char *ft_split_join(char **splited)//미완성
{
	int i;
	int len;
	char *r;

	i = -1;
	len = 0;
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

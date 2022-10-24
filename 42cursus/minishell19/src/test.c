/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/23 20:58:13 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include "minishell3.h"
#include "test.h"
#include "libftprintf.h"
# include <signal.h>
# include <unistd.h>

#include <stdio.h>

//# include <readline/readline.h>
//# include <readline/history.h>


int	main(int argc, char **argv, char **envp)
{
	t_list *env;

	//char *s = "echo aaa | cat > \"a.txt||\" | chmod 755 < \'asd\" | < >asd \' asd";
	char *s = "<t.txt >>a.txt $XPC_FLAGS ./a.out -n \"abcd cat > $PATH a.txt\" abc > $a c.txt b.txt << end";
	//char *s = " $?a";
	char *l;
	int status;
	t_list *token_start;

	splited_2_strlist(&env, envp);

	print_splited(envp, "envp");
	
	ft_lstadd_back(&env, ft_lstnew(ft_strdup("?=12")));

	print_strlist(env, "env");


	l = label_text(s);
	ft_printf("%s\n%s\n", s, l);

	//status = tokenize("echo aaa >> a.txt", &token_start);
	status = tokenize(s, &token_start);

	if (!status)
	{
		print_token_list(token_start, "tokenized");
	}

	//if (DEBUG) ft_printf("PATH =%s\n", get_envp("PATH", env));

	if (!status)
		status = variable_expansion(token_start, env);

	if (!status)
	{
		print_token_list(token_start, "expanded");
		//int i = -1;
		//int len = ft_lstsize(token_start);

		//while (++i < len)
		//	print_token(ft_lstnth(token_start, i)->content, "a", 0);
	}


	//system("leaks test");
}

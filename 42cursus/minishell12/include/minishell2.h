/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:42:31 by snoh              #+#    #+#             */
/*   Updated: 2022/09/25 04:44:45 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libftprintf.h"
# include "sorter.h"
# include "stack_ab.h"
# include "stack.h"
# include <limits.h>


// The smallest unit in which a process runs
// matched with 1 process
typedef struct s_excutable
{

	char				*processed_text;
	
	// full path
	char				*excutable_path;
	char				*argv[];
	char				*envp[];
	// 3 above them are should be freed

	int					state;
}t_e;

// The smallest unit in which an instruction is executed
typedef struct s_job
{
	// "part of the command" that executed on this structure
	char				*text;

	int					num_of_excutables;
	struct s_excutable	*excutables[];

	// full path
	char				*input_redirects;
	char				*output_redirects;


	int					state;
	//100 : 파싱 중 메모리할당 안됨


	struct s_memory_box	mbox;

}t_j;

// Command entered by the user
typedef struct s_command
{
	// The smallest unit in which an instruction is executed
	char				*text;

	int					num_of_runnables;
	struct s_job		*jobs[];

	//something			*runnable_structure : for bonus

	int					state;

}t_c;

typedef struct s_minishell_program
{

// initial value
	int					initial_argc;
	char				*initial_argv[];
	char				*initial_envp[];

// environment variables for shell
	char				*envp[];

// for minishells
	char				*now_path;

	struct s_command	command;

	int					recent_exit_code;

	int					error_flag;


}t_mp;



/*Main : push_Swap & checker*/
void	exit_by_error(int i);
int		is_sorted(int *list);

/*Check_input*/
int		*check_input(int argc, char **argv);

/*Memory Manage*/
void	collector(void *pointer);

#endif	
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_lagacy-minishell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/03 11:31:30 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	struct s_minishell_program *mp;

	initialize(mp);
	while(mp->error_flag == 0)
	{
		prompt(mp);
		process_command(mp);
	}

	ready_for_exit(mp);
	return (0);
}




initialize(mp, argc, argv)
{
	// allocate and initialize mp structure
	// set signal handlr
	// get envp

}


prompt(mp)
{
	// if minishell run non-interactive mode, then skip prompt 

	// get command from user
	// and save it on mp->command.text
	// and change mp->command.state
}

process_command(mp)
{
	//parse_structure(); 				for bonus
	//pre_process_cmd(mp/*->runnable*/);
		// $ variable conversion
	//cmd_to_structure(mp/*->runnable*/);
		//
	run_commands_in_order(mp/*->command*/)	
	
	//post_process(mp/*->command*/)
		// heredoc << redirection x;
	//processing...
}

run_commands_in_order(mp/*->command*/) // 보너스 때문에
{
	while(until_done)
	{
		parse(mp, runnable);
		run(mp, runnable); << 여기!!
	}
}

run(t_mp *mp, s_runnable *runnable); << 이 함수!!
// mp는 상태 기록용
// runnable 구조체를 보고 프로세스 실행!

void parse(t_mp *mp, t_r *runnable)
{
	// runnable 은 text만 채워진 상태로 받는다.

	if (runnable->state == 0)
		runnable->state = command_to_jobs(s_command);
	if (runnable->state == 0)
		runnable->state = parse_structure(runnable);
			// make excution structure
	if (runnable->state == 0)
		runnable->state = parse_post_process(runnable);
			
			// make heredoc file
}



int parse_structure(t_mp *mp, t_r *runnable)
{
	split_into_excutables(runnable);
	
	parse_excutables_text(runnable);
	variable_expansion(runnable);
	filename_expansion(runnable);
	
	quote_remove(runnable)
}

parse_post_process(runnable);




//runnable을 받아서 거기에 저장되어 있는 text를 보고
// 파이프 단위로 나누어서 excutable을 생성하고 각각 담은 뒤
// runnable의 excutables에 포인터 리스트로 담아둔다, 맨 마지막 excutable 뒤의 값은 0 포인터 (리스트의 끝을 알려줌)
void split_into_excutables(t_mp *mp, t_r *runnable)
{
	t_mbox	trash_can;
	char	**pipe_split;

    trash_can.cur = 0;	
	collector(&trash_can, 0);//initialize
	
	pipe_split = ft_split(runnable->text, '|'); // malloc 예외처리
	if (pipe_split == 0)
	{
		runnable->state = 100;
		return (0);
	}


	//job을 받아서 그 텍스트 내용을 토대로
	// excutable을 만들고 그안에 텍스트 구겨담기
	int i = -1;
	runnable->num_of_excutables = 0;

	while (pipe_split[runnable->num_of_excutables])
		runnable->num_of_excutables++;

	while (pipe_split[++i])//job 만들고 그 안에 excutable 옮겨담기 (excutable 만들기)
	{
		runnable->excutables[i] = ft_calloc(sizeof(s_excutable), num_of_excutables + 1);
		if (collector(runnable->mbox, runnable->excutables) == 0) // malloc 예외처리
			return (0);
		runnable->excutables[i].text = pipe_split[i]; // 자 할일 다 했다 다음으로 넘어가자
		runnable->excutables[i].envp[] = mp->envp;

	}
	free (pipe_split); // 여기까지 excutable 만들어서 text 옮겨닯기 끝, envp 주소도 넘겨줌

	// 그 다음은 excutable 마다 리디렉션을 들어내서 저장하는 것
	// 리디렉션을 들어낼 때에는 따옴표에 주의하여 들어내야 한다.

}

// runnable을 돌면서
// excutable의 text 맨 위에 공백을 하나 집어넣고
// excutable의 파싱용 텍스트 변수에 리다이렉션과 명령어를 채워넣는다.

int parse_excutables_text(t_r runnable)
{
	int i;
	char *temp_str
	t_e *exc;

	i = -1;

	while(runnable->excutables[++i])
	{
		exc = &runnable->excutables[i];
		exc -> excutable_path = ft_calloc(sizeof(char), ft_strlen(exc->text) + 1);
		exc -> redirections = ft_calloc(sizeof(char), ft_strlen(exc->text) + 1);
		temp_str = ft_mprintf("%s ", exc -> text);
		free(exc->text);
		exc->text = temp_str;

		excutables_tokenize(exc->text, exc->redirections, exc->excutable_path);
		ft_printf("redirection : %s \n", exc->redirections);
		ft_printf("excutable   : %s \n", exc->excutable_path);
	}

}









/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_0_minishell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 04:06:08 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	post(t_mp *mp)
{
	if (mp->error_flag != 0 || !mp->runnable)
		return (0);
	destruct_runnable(mp->runnable);
	mp->runnable = 0;
	return (0);
}

void	handle_error(t_mp *mp)
{
	if (mp->error_flag == 1)
		ft_eprintf("error : The syntax is not executable.\n");
	else if (mp->error_flag == 2)
		ft_eprintf("error : Variable extension failed.\n");
	else if ("When only EOF came in" && mp->error_flag == 42)
		return ;
	mp->error_flag = 0;
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	struct s_minishell_program	*mp;

	if (initialize(&mp, argc, argv, envp))
		return (1);
	g_pid = NULL;
	while (mp->error_flag == 0)
	{
		prompt(mp);				//프롬프트 : 문자열을 받는다 
		//process_command(mp);	//문자열을 파싱하고 실행
		parse(mp);
		//print_runnable(mp->runnable, "parsed runnable");
		run(mp);
		//print_runnable(mp->runnable, "runed");
		//print_runnable(mp->runnable, "runed");
		post(mp);
		//system("leaks minishell");
		handle_error(mp);		//한바퀴 돌 떄마다, 오류가 났는지 확인하고 오류를 처리
	}
	//ready_for_exit(mp);
	return (0);
}

/*
** Parameter    : 미니셸 프로그램 구조체
** Return value : void
**					0 : 처리가 정상적으로 완료됨
**					1 : 처리에 문제가 생김
** Description  : mp에 입력된 문자열을 받아서 token으로 변환하고, 
**					변수 확장, 따옴표 제거, 부분으로 나누기를 한 다음
**					runnable로 정리한다.
**
** ErrorHandle  : error 가 나면 mp-> error_flag를 수정한다.
**					0 : 정상 상태
**					1 : 오류 생김
**
**
*/
/*
void parse(t_mp *mp)
{
	t_list	*token_start;

	if (mp->error_flag)
		return ;


	token_start = 0;

	if (tokenize(mp->command, &token_start))//만약 토크닝에서 오류가 난 경우
	{
		mp->error_flag = 1;//이런 식으로 예외처리 하시오 
		return;
	}
	if (DEBUG) print_token_list(token_start, "tokenized"); // 디버그 구문


	if (variable_expansion(token_start, mp->envp))//만약 익스펜션에서 오류가 난 경우
	{
		mp->error_flag = 1;//이런 식으로 예외처리 하시오 
		return;
	}

	if (DEBUG) print_token_list(token_start, "expanded"); // 디버그 구문


	// 따옴표 떼어내기
	// 옮겨담기
		// 실행 부분은 file name expansion;
		// argv 부분 떼어네서 argv 만들기
		// redirection 부분 뗴어내기
	// 디바이드 하기 (redirection 부분의 text 만 )


}
*/
/*
int run(t_mp *mp, t_r *runnable)
{
	int i;
	int j;

	i = -1;
	while(runnable->excutables[++i])
	{
		j = -1;
		while (runnable->excutables[i]->argv[++j])
			ft_printf("argv[%d]:%s\n", j, runnable->excutables[i]->argv[j]);

	}
return (0);	
}*/
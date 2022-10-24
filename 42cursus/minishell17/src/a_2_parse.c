/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_1_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/23 20:56:15 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

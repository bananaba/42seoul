/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_3_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/25 00:08:43 by snoh             ###   ########.fr       */
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
	
	// text 나누기_____________ 중요!!! 이거 해야 됌
//	divide_text_in_token(token_start);

	// 따옴표 떼어내기 -> 그리고 모두 text로 바꾼다.
	remove_quote(token_start);

	if (DEBUG1) print_token_list(token_start, "double_quote"); // 디버그 구문


	/* testing linkedlist_2_array()
	t_token ** tokens;
	tokens = linkedlist_2_array(&token_start);

	ft_printf("now print tokens in array !\n");
	int i = -1;
	while(tokens[++i])
		print_token(tokens[i], "array!!!", 1);
	*/

	//if (DEBUG) ft_printf("now token_start is %p\n", token_start);

	convert_to_runnable(mp, &token_start);



	// 옮겨담기
		// 실행 부분은 file name expansion;
		// argv 부분 떼어네서 argv 만들기
		// redirection 부분 뗴어내기
	// 디바이드 하기 (redirection 부분의 text 만 )


}

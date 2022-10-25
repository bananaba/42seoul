/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:56:05 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 04:06:44 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// quote_remove
int		count_pipe_in_tokens(t_list *token_start);
void	token_2_listarray(t_list **listarray, t_list *token_start);
t_list	**convert_token_2_listarray(t_list *token_start);
int		convert_to_runnable(t_mp *mp, t_list **token_start);
t_e		*exchange_token_2_excutable(t_list **token_start, t_list *envp);
void	remove_meaningless_tokens(t_list *token_start);
void	move_redirection_tokens(t_e *excutable, t_list **token_start);
void	*token_2_string(void *pointer);
int		make_argv(t_e *excutable, t_list **token_start);

/*
** Parameter    : 토큰 연결 리스트의 시작 부분
** Return value : 처리 결과
**					0 : 처리가 정상적으로 완료됨
**					1 : 처리에 문제가 생김 (이거 나올 일 없을 것 같은데)
** Description  : 토큰의 시작점을 받아서 대응되는 정보를 가진 runnable 을 mp 구조체에 달아준다.
**
** Implemente	:	1. 파이프 단위로 토큰을 잘라서 배열에 담는다.
**					2. 배열에 담긴 토큰리스트를 excutable로 변환한다.
**						이거 중간에 오류나면 처리가 곤란해져서
						excutable_array을 하나 만드는 것으로 타협을 봤어
**					//3. linkedlist를 array로 바꾸어, runnable에 담는다.
					3. 변환하면서 새로운 배열로 옮겨담는다.
**
*/
int	convert_to_runnable(t_mp *mp, t_list **token_start)
{
	int		i;
	t_list	**token_listarray;
	t_r		*runnable;

	runnable = new_runnable_with_size(count_pipe_in_tokens(*token_start) + 1);
	token_listarray = convert_token_2_listarray(*token_start);
	if (token_listarray && runnable)
	{
		if (DEBUG1) //print token_listarray
		{
			i = -1;
			while (token_listarray[++i])
				print_token_list(token_listarray[i], "tokens in splitted");
		}
		i = -1;
		while (token_listarray[++i])
			runnable->excutables[i] = exchange_token_2_excutable(&token_listarray[i], mp->envp);
	}
	if (token_listarray)
	{
		free(token_listarray);
		token_listarray = 0;
	}
	mp->runnable = runnable;
	return (0);// 정상적으로 removal되면 0을 리턴한다.
}


/*
** Parameter    : 파이프가 없는 토큰 연결 리스트의 시작 부분
**					
**					
** Return value : 그와 동등한 excutable 구조체
**				  오류가 나면 0
**
** Description  : 토큰의 시작부분을 받아, 새로 생성한 excutable 구조체에 정보를 담아 리턴한다.
**
** Implemente	:	1. excutable을 생성한다.
**					2. 하나씩 옮겨담는다.
						2-1. 의미 없는 토큰을 전부 지운다.
						2-2. 리디렉션 토큰을 excutable로 옮긴다.
						2-3. 남은 토큰을 argv로 바꾼다.
**					3. 리턴한다.
**					
*/
t_e	*exchange_token_2_excutable(t_list **token_start, t_list *envp)
{
	t_e	*excutable;

	excutable = new_excutable(envp);
	if (excutable)
	{
		//if (DEBUG1) print_token_list(*token_start, "before_remove_meaningless_tokens");
		remove_meaningless_tokens(*token_start);
		//if (DEBUG1) print_token_list(*token_start, "meaningless_tokens_removed");
		move_redirection_tokens(excutable, token_start);
		//if (DEBUG1) print_token_list(excutable->redirections, "redirections");
		//if (DEBUG1) print_token_list(*token_start, "for argv");
		make_argv(excutable, token_start);
	}
	return (excutable);
}


/*
** Parameter    : excutable 구조체 , argv 부분만이 남은 type t 토큰들
**							
** Return value : 성공 여부
**					0 : 성공
**					1 : 실패
**				  
** Description  : 남은 token_start를 이용해서 excutable의 argv를 채운다.
**	
**	
*/
int	make_argv(t_e *excutable, t_list **token_start)
{
	t_list	*text_list;

	text_list = 0;
	text_list = ft_lstmap(*token_start, token_2_string, free);
	ft_lstclear(token_start, do_nothing);
	//if (DEBUG1) print_strlist(text_list, "make_argv : text_list");
	if (text_list)
	{
		excutable->argv = (char **) linkedlist_2_array(&text_list);
		//if (DEBUG1)	print_splited(excutable->argv, "make_argv : splitted");
		return (0);
	}
	else
	{
		ft_lstclear(token_start, (void (*)(void *)) destroy_token);
		return (1);
	}
}

void	*token_2_string(void *pointer)
{
	t_token	*token;
	char	*r;

	token = (t_token *)pointer;
	r = 0;
	if (token)
	{
		r = token->text;
		token->text = 0;
		free(token);
	}
	return (r);
}



/*
** Parameter    : excutable 구조체 , ( t, (r, l) 토큰으로만 이루어진 토큰 리스트의 시작 부분)
**							
** Return value : 없음
**				  
** Description  : excutable 구조체의 redirection 부분에 연결리스트를 채운다.
**	
**	
*/
void	move_redirection_tokens(t_e *excutable, t_list **token_start)
{
	int		i;
	t_list	*now;
	t_token	*now_token;

	i = 0;
	while (ft_lstnth(*token_start, i))
	{
		//if (DEBUG1) print_token_list(token_start, "token_start in  move_redirection_tokens");
		now = ft_lstnth(*token_start, i);
		now_token = (t_token *) now->content;
		if (now_token->type == 'r' || now_token->type == 'l')
		{
			ft_lstadd_back(&(excutable->redirections),
				ft_lstpop_nth_p(token_start, i));
			ft_lstadd_back(&(excutable->redirections),
				ft_lstpop_nth_p(token_start, i));
		}
		else
		{
			i++;
		}
	}
}


/*
** Parameter    : t, (r, l) 토큰으로만 이루어진 토큰 리스트의 시작 부분
**							
** Return value : 없음
**				  
** Description  : 토큰 리스트에서 의미 없는 텍스트 부분을 모두 지운다.
**	
**	(이것도 테스트는 못 했는데, 일단은 완성)
*/

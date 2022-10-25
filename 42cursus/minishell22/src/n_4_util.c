/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_4_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 03:47:19 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 03:49:46 by balee            ###   ########.fr       */
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

void	remove_meaningless_tokens(t_list *token_start)
// 맨 앞에 있는 토큰은 안 지워지니까, t_list **  대신 *t_list를 받는다.
{
	int		state;
		// 1 아직 발견 안 함
		// 2 발견하고 점프하는 중
		// 0 이미 다 발견함
	t_list	*now;
	t_token	*next_token;

	now = token_start;
	state = 1;
	if (((t_token *)token_start->content)->type == "text"[0])  // 만약에 첫번째가 text인 경우
		state = 2;													// 발견하고 점프하는 중으로 하면 되지
	else														// 이건 첫번쨰가 l 이거나 r 인경우
		now = now->next;											// 이건 그 다음 text를 넘기면 되는 일
	while (now && now->next)
	{
		if (DEBUG1)
			print_token((t_token *) now->content, "now token", 1);
		if (DEBUG1)
			print_token((t_token *) now->next->content, "next token", 1);
		if (DEBUG1)
			printf("state = %d\n", state);
		next_token = (t_token *) now->next->content;
		if (next_token->type == "text"[0]) //만약 다음 토큰이 text인 경우 (아니 그러면 처음 토큰이 리다이렉트면 어떻게 하려고 )
		{
			if (state == 0) // 만약 다 찾았는데, t가 들어오면
			{
				ft_lstdel_next(now, (void (*)(void *)) destroy_token);//지운다. (맨 마지막은 알아서 처리 된다.)
				continue ;
			}
			else if (state == 1)
				state = 2;
		}
		else// r 이거나 l인 경우
		{
			if (state == 2)//여기에 들어 왔는데 argv부분을 찾던 중이였다면
				state = 0;//다 찾은 것임
			now = now->next;// 다음 t를 바로 넘기고 그 다음을 확인 하도록 한다.
		}
		now = now->next;
	}
}



/*
** Parameter    : 토큰 연결 리스트의 시작 부분
**				  * 작동 조건
**					1. 시작하자 마자 파이프 오면 안됨		 (이건 유효성 검증떄 구현됨)
**					2. 파이프 다음에 아무것도 없으면 안됨 
**					
**					
**					
** Return value : 토큰리스트를 파이프 단위로 나누어 담긴 토큰 리스트배열.
**
** Description  : 토큰의 시작부분을 받으면, 토큰 리스트를 파이프 단위로 나누어 여러 조각으로 만들고
**				  이 조각들을 새로운 배열에 담아서 리턴한다.
**
** Implemente	:	1. 파이프의 갯수를 센다
**					2. 담을 리스트배열을 만든다.
**					3. 하나씩 잘라 담는다.
**					
**					
**					
*/
t_list	**convert_token_2_listarray(t_list *token_start)
{
	int		num_pipe;
	t_list	**listarray;

	num_pipe = count_pipe_in_tokens(token_start);
	listarray = ft_calloc(sizeof(t_list *), num_pipe + 2);
	if (listarray)
	{
		listarray[num_pipe + 1] = 0;
		token_2_listarray(listarray, token_start);
	}
	return (listarray);
}



/*
** Parameter    : 토큰 리스트리스트의 시작 부분, 토큰 연결 리스트의 시작 부분
**
**					
** Return value : void (문제 생길 여지 없다.)
**
** Description  : 토큰의 시작부분을 받으면, 토큰 리스트를 파이프 단위로 나누어 여러 조각으로 만들고
**				  이 조각들을 listlist에 담는다.
**
** Implemente	:	1. 순회하면서
**						1-2. 이번 노드가 파이프 노드라면
**							1-2-1. 다음 연결리스트에 옮겨담고, p에 저장한다.
**							1-2-2. 
**							1-2-3. 파이프 다음 노드를 배열에 옮겨담는다.
**					
** (이것도 일단은 완성이 된 것 같은데 검증 하려니까 너무 귀찮다.)					
**					
*/

void	token_2_listarray(t_list **listarray, t_list *token_start)
{
	int		i;
	t_list	*now;
	t_list	*prev;
	t_token	*now_token;

	i = -1;
	now = token_start;
	listarray[++i] = token_start;
	while (now)
	{
		now_token = (t_token *)now->content;
		if (now_token->type == "pipe"[0])// 만약 now가 pipe이면
		{
			prev->next = 0;	// 파이프 이전 토큰을 여기서 닫는다.
			prev = now;
			now = now->next;
			ft_lstdelone(prev, (void (*)(void *)) destroy_token);// 파이프 토큰을 담은 노드를 지운다.
			listarray[++i] = now;// 파이프 다음에 바로 시작하는 토큰의 주소를 추가
		}
		prev = now;
		now = now->next;
	}
}


/*
** Parameter    : 토큰 연결 리스트의 시작 부분
**
** Return value : 토큰리스트에 연결된 파이프 토큰의 갯수
**
** Description  : type이 pipe[0]인 토큰의 갯수를 세어 리턴한다.
**
** (테스트는 안 했지만 일단 완성)
*/
int	count_pipe_in_tokens(t_list *token_start)
{
	int		num_pipe;
	t_list	*p;

	num_pipe = 0;
	p = token_start;
	while (p)//파이프의 갯수를 샌다.
	{
		if (((t_token *) p->content)->type == "pipe"[0])
			num_pipe++;
		p = p->next;
	}
	return (num_pipe);
}

/*
** Parameter    : 토큰 연결 리스트의 시작 부분
** Return value : 처리 결과
**					0 : 처리가 정상적으로 완료됨
**					1 : 처리에 문제가 생김 (이거 나올 일 없을 것 같은데)
** Description  : 토큰의 시작부분을 받으면, 받은 부분부터 파이프 토큰 직전까지의 토큰을 잘라서
**				  
**
**

 < asd 444 444 > asd 123 << asd 123 123 123 < asd 123

int make_excutable(t_list *token_start, int len)
{

}
*/

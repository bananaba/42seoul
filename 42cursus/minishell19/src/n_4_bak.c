
#include "test.h"

// quote_remove
int remove_quote(t_list *token_start);
int remove_quote_token(t_token *quote_token);

static int count_pipe_in_tokens(t_list *token_start);


/*
** Parameter    : 토큰 연결 리스트의 시작 부분
** Return value : 처리 결과
**					0 : 처리가 정상적으로 완료됨
**					1 : 처리에 문제가 생김 (이거 나올 일 없을 것 같은데)
** Description  : 토큰의 시작점을 받아서 대응되는 정보를 가진 runnable 을 mp 구조체에 달아준다.
**
** Implemente	:	1. 파이프 단위로 토큰을 잘라서 연결 리스트에 담는다.
**					2. 연결 리스트에 담긴 토큰리스트를 excutable로 변환한다.
**					3. linkedlist를 array로 바꾸어, runnable에 담는다.
**
*/
int convert_to_runnable(t_mp *mp, t_list *token_start)
{
	t_list *token_listlist;
	
	token_listlist = token_2_listlist(token_start);

	
	return (0);// 정상적으로 removal되면 0을 리턴한다.
}



/*
** Parameter    : 토큰 연결 리스트의 시작 부분
**				  * 작동 조건
**					1. 시작하자 마자 파이프 오면 안됨		 (이건 유효성 검증떄 구현됨)
**					2. 파이프 다음에 아무것도 없으면 안됨 
**					
**					
**					
** Return value : 토큰리스트를 파이프 단위로 나누어 담긴 토큰 리스트리스트.
**
** Description  : 토큰의 시작부분을 받으면, 토큰 리스트를 파이프 단위로 나누어 여러 조각으로 만들고
**				  이 조각들을 새로운 리스트에 담아서 리턴한다.
**
** Implemente	:	1. 파이프의 갯수를 센다
**					2. 담을 리스트리스트를 만든다.
**					3. 하나씩 잘라 담는다.
**						3-1. 순회하면서
**						3-2. 다음 노드가 파이프 노드라면 (다음 노드가 없다면 거기서 끝)
**							3-2-1. next를 다음 연결리스트에 옮겨담고, p에 저장한다.
**							3-2-1. next를 0으로 만든다. (방법을 찾아야 해)
**							3-2-2. #파이프 노드 다음에 노드가 있는지 확인한다. (이건 유효성 검증 떄 해)
**							3-2-3. 파이프 다음 노드를 
**						3-3. 
**					
*/
static t_list convert_token_2_listlist(t_list *token_start)
{
	int num_pipe;


	t_list *listlist;

	now_token = 0;
	prev = 0;
	num_pipe = count_pipe_in_tokens(token_start);
	
	listlist = ft_calloc(sizeof(t_list *), num_pipe + 2);
	if (listlist)
	{
		token_2_listlist(&listlist, token_start);
	}
	return (listlist);
}



/*
** Parameter    : 토큰 리스트리스트의 시작 부분, 토큰 연결 리스트의 시작 부분
**
**					
** Return value : 처리 결과
**					0 : 처리가 정상적으로 완료됨
**					1 : 처리에 문제가 생김 (이거 나올 일 없을 것 같은데)
**
** Description  : 토큰의 시작부분을 받으면, 토큰 리스트를 파이프 단위로 나누어 여러 조각으로 만들고
**				  이 조각들을 listlist에 담는다.
**
** Implemente	:	1. 순회하면서
**						1-2. 다음 노드가 파이프 노드라면 (다음 노드가 없다면 거기서 끝)
**							1-2-1. next를 다음 연결리스트에 옮겨담고, p에 저장한다.
**							1-2-1. next를 0으로 만든다. (방법을 찾아야 해)
**							1-2-2. #파이프 노드 다음에 노드가 있는지 확인한다. (이건 유효성 검증 떄 해)
**							1-2-3. 파이프 다음 노드를 
**					
*/
int token_2_listlist(t_list **listlist, t_list *token_start)
{
	t_list *start;
	t_list *prev;
	t_list *node;
	t_token *now_token;

	now = token_start;
	start = token_start;

	while(now)
	{
		now_token = (t_token *) now->content;
		if (now_token->type == "pipe"[0])
		{
			prev->next = 0;
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
**
*/
static int count_pipe_in_tokens(t_list *token_start)
{
	int num_pipe;
	t_list *p;

	num_pipe = 0;
	p = token_start;
	while (p)//파이프의 갯수를 샌다.
	{
		if ((t_token) p->content->type == "pipe"[0])
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
*/
int make_excutable(t_list *token_start, int len)
{

}

/*
** Parameter    : 따옴표 토큰,
** Return value : 처리 결과
**					0 : 처리가 정상적으로 완료됨
**					1 : 처리에 문제가 생김
** Description  : 토큰의 문자열을 보면서 변수 부분을 해당하는 envp의 값으로 대체한다.
**	
*/
int remove_quote_token(t_token *quote_token)
{
	char	*str;
	int		len;

	str = quote_token->text;
	len = ft_strlen(str);
	ft_strlcpy(str, &str[1], len - 1);
}




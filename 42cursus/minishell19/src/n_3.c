
#include "minishell.h"

// quote_remove
int remove_quote(t_list *token_start);
int remove_quote_token(t_token *quote_token);



/*
** Parameter    : 토큰 연결 리스트의 시작 부분
** Return value : 처리 결과
**					0 : 처리가 정상적으로 완료됨
**					1 : 처리에 문제가 생김 (이거 나올 일 없을 것 같은데)
** Description  : 토큰의 시작점을 받아서 토큰을 순회하며, type이 "quote"[0]인 토큰과
**				  "double_quote"[0]인 토큰들의 문자열 중
**				  맨 앞과 뒤에 있는 quote를 지운다.
**
**
*/
int remove_quote(t_list *token_start)
{
	t_list *now;
	t_token *now_token;

	now = token_start;

	while (now)// 토큰을 순회하면서
	{
		now_token = (t_token *) now->content;
		if (DEBUG) print_token(now_token, "now_token", 0);


		if (now_token->type == "quote"[0] || now_token->type == "double_quote"[0])
		{//만약 토큰이 quote이거나 double_quote이면
			remove_quote_token(now_token);// 띠옴표를 지운다. 이건 문제 생길 소지 없어 
			now_token->type = "text"[0];		//따옴표를 지우고 나면 text로 바꾸어준다.
		}
		if (DEBUG) print_token(now_token, "processed_token", 1);
		now = now->next;// 
	}

	return (0);// 정상적으로 removal되면 0을 리턴한다.

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
	return (0);
}




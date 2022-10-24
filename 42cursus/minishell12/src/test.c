/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/20 06:33:39 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "libftprintf.h"
# include <signal.h>
# include <unistd.h>

#include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>



typedef struct s_token
{
	char	type;
	// pipe[0] 
	// text[0]
	// quote[0]
	// double_quote[0]
	// redirection[0]
	// ledirection[0]
	// space[0]
	char	*text;
}	t_token;

void destroy_token(t_token *token);
t_token *new_token(char atype, char *atext);
void print_token(t_token *token, char *name ,int tabs);
int tokenize(char *text, t_list** token_start);
static t_list *label2token(char *text, char *labels);
static int connect_token(t_list **token_start, t_list *token_node);
static t_list *make_token_here(char *text, char *labels, int i);
static int check_label(char *labels);
char*	label_text(char *text);
static void mark_quote(char *text, char *labels, int *idx, int len);
static void mark_not_quote(char *text, char *labels, int i);





void destroy_token(t_token *token)
{
	if (token->text)
		free(token->text);
	free(token);
}

t_token *new_token(char atype, char *atext)
{
	t_token *r;

	r = ft_calloc(sizeof(t_token), 1);
	if (r)
	{
		r->type = atype;
		r->text = atext;
	}
	return (r);
}

void print_token(t_token *token, char *name ,int tabs)
{
	char n[1000];

	memset(n, '\t', int_min(tabs, 999));
	n[int_min(tabs, 999) + 1] = 0;

	if (token)
	{
		ft_printf("%sprint token : %s \n", n, name);
		ft_printf("%s\t%s->type = %c\n",n ,name, token->type);
		ft_printf("%s\t%s->text = %s\n",n ,name, token->text);
	}
	else
	{
		ft_printf("%stoken %s is (null) : t \n", n, name);
	}

}


/*
** Parameter    : 셸의 입력 텍스트
** Return value : 처리 상태
**					0 : 처리가 정상적으로 완료됨
**					1 : 처리에 문제가 생김
** Description  : 셸의 입력 텍스트를 받아서, 토큰들을 생성한다.
**				 token_start에 생성한 토큰을 연결한다.
*/
int tokenize(char *text, t_list **token_start)
{
	char *labels;
	
	labels = label_text(text);	// 텍스트에 라벨을 붙입니다!
	if (check_label(labels));					// 라벨을 보고 잘못된 것을 걸러냅니다.
		//라벨이 잘못된 경우 예외처리
	*token_start = label2token(text, labels);	// 토큰에 옮겨 담습니다.								
	//if (check_token(*token_start))				// 토큰을 보고 잘못된 것을 걸러냅니다.
		// 토큰이 이상한 경우 예외처리

												// 마무리하고 리턴하니다.
}




/*
** Parameter    : 	셸의 입력 텍스트, 
**					label_text가 생성한 라벨 (토큰으로 나눌 수 없는 것들은 들어오면 안 됨)
** Return value : 	토큰으로 나누어 담은 연결리스트의 시작 노드 주소
**					
** Description  :   텍스트를 토큰으로 나누어 연결리스트에 담습니다.
**
** Implement	:	라벨이 같은 한 묶음을 하나의 토큰에 담습니다. space 는 토큰으로 담지 않습니다.
**
** 완성됨(수정할때 위에 설명도 수정해주세요!)
*/
static t_list *label2token(char *text, char *labels)
{
	int		i;
	int		len;
	t_list	*token_node;
	t_list	*token_start;
	
	token_start = 0;
	len = ft_strlen(text);
	i = 0;

	if (labels[i] != 's')// 맨 처음 문자는 <space>만 아니라면 일단 토큰 생성
	{
		token_node = make_token_here(text, labels, i);
		if (connect_token(&token_start, token_node))
			return 0;
	}

	while(++i < len)// 그 다음부터는 <space> 가 아닌 새로운 문자가 나타날 때마다 토큰 생성
	{
		if (labels[i] != 's' && labels[i - 1] != labels[i])	
		{
			token_node = make_token_here(text, labels, i);
			if (connect_token(&token_start, token_node))
				return 0;
		}
	}

	return(token_start);

}



/*
** Parameter    : 	줄줄이 토큰의 시작 부분
**					새로운 토큰 노드 주소
**
** Return value : 	잘 연결되었다면 0
**					문제가 생겨서, token_start 와 token_node를 정리했다면 1
**					
** Description  :   주어진 토큰노드를 토큰 스타트 맨 뒤에 붙입니다. 
**					만약 문제가 있다면 토큰 스타트 리스트와, 토큰 노드를 free합니다.
**
**					이 함수가 발견할 수 있는 문제
**						1. token_start 가 null인 경우
**						2. token_node  가 null인 경우
**
** Implement	:	
**
** 완성됨(수정할때 위에 설명도 수정해주세요!)
*/
static int connect_token(t_list **token_start, t_list *token_node)
{

	if (token_node == 0 || token_start == 0)
	{
		ft_lstclear(token_start, destroy_token);
		ft_lstdelone(token_node, destroy_token);
		return (1);
	}
	else
	{
		ft_lstadd_back(token_start, token_node);
		return (0);
	}
}

/*
** Parameter    : 	셸의 입력 텍스트, 
**					label_text가 생성한 라벨 (토큰으로 나눌 수 없는 것들은 들어오면 안 됨)
**					토큰을 만들 text의 위치 i
**
** Return value : 	새로 생성된 토큰을 넣은 새로 생성된 연결리스트 노드
**					중간에 문제가 생긴다면 0을 리턴
**					
** Description  :   주어진 정보로 토큰을 만들어 새로 만든 연결리스트 노드에 담고, 그 노드의 주소를 리턴합니다.
**
** Implement	:	주어진 부분부터, 라벨이 같은 한 묶음의 텍스트를 이용해 새로운 토크을 만듭니다.
**					만든 토큰을 새로운 연결리스트 노드에 넣고, 연결리스트 노드의 주소를 리턴합니다.
**
** 완성됨(수정할때 위에 설명도 수정해주세요!)
*/
static t_list *make_token_here(char *text, char *labels, int i)
{
	int		len;
	t_token	*token;
	t_list	*node;

	len = 0;
	while(labels[i + len] == labels[i])//len에는 한 토큰에 들어갈 문자열의 길이가 담긴다.
		len++;


	node = ft_lstnew(0);
	token = new_token(0, 0);
	if (token)	// 토큰이 정상적으로 생성되었다면, 라벨을 붙이고 텍스트를 복사한다. 
	{
		token->text = ft_substr(text, i, len);
		token->type = labels[i];
	}

	if (!(node && token && token->text))// 처리가 잘 되었는지 확인하고 리턴한다.
	{
		free(node);
		destroy_token(token);
		return (0);
	}
	else
	{
		node->content = token;
		return node;
	}

}





/*
** Parameter    : 	셸의 입력 텍스트
** Return value : 	라벨이 정상이라면 0
**					라벨이 비정상이라면 1, 또는 다른 숫자들
**					
** Description  :   라벨을 보고 걸러낼 수 있는 문맥 오류를 걸러냅니다.
**					이는 토큰으로 옮겨 담을 떄 오류가 없도록 하기 위함입니다.
**					(말인 즉슨 토큰으로 옮겨 담고 나서 문맥 오류를 한번 더 잡아야 한다는 것)
**						1. pipe 가 두개 이상 연속으로 오는 경우
**						2. redirection 과 ledirection이 붙어있는 경우
**						3. redirection 또는 ledirection이 3개 이상 연속된 경우
**						4. 모든 문자열이 space인 경우
**						(수정할떄 추가하세요)
**
**
** 완성됨(수정할때 위에 설명도 수정해주세요!)
*/
static int check_label(char *labels)
{
	int len;

	len = ft_strlen(labels);
	
	// pipe가 2개 이상 연속으로 나오는 경우
	if (ft_strnstr(labels, "pp", len))
		return (1);

	// redirection 과 lidirection이 붙어있는 경우
	if (ft_strnstr(labels, "rl", len) != 0 || ft_strnstr(labels, "lr", len) != 0) 
		return (1);

	// redirection 또는 lidirection이 3개 이상 연속된 경우
	if (ft_strnstr(labels, "rrr", len) != 0 || ft_strnstr(labels, "lll", len) != 0) 
		return (1);

	// 모든 문자열이 space로 이루어진 경우
	if (ft_strlen_s(labels, "prlqdt") == len)
		return (1);

	// 한번도 안 걸리면 정상
	return (0);
}


/*
** Parameter    : 	셸의 입력 텍스트
** Return value : 	오류가 있다면 0 포인터 , 정상의 경우
**					입력 텍스트의 quote 위치가 'q', double quote 위치가 'd',
**					pipe의 위치가 'p', redirection의 위치가 < 'l' > 'r' 
**					그냥 문자열은 't' , 그중 space는 's'로 표지된 새로운 문자열
**					
** Description  :   입력을 받아서 텍스트의 각각의 요소를 표지한 새로운 텍스트를 생성하여 반환한다.
** 완성됨
*/
char*	label_text(char *text)
{
	int		i;
	int		stat;
	int		len;
	char 	*labels;

	len = ft_strlen(text);

	if (len == 0)//아무것도 입력 안 한 경우 예외처리
		return (0);

	labels = ft_calloc(sizeof(char), len + 2);

	i = -1;
	stat = 0;
	while (++i < len && labels)
	{
		if (ft_isquote(text[i]))
			mark_quote(text, labels, &i, len);
		else
			mark_not_quote(text, labels, i);
	}
	if (labels && labels[len])
	{
		// 이 안에 들어오면 qoute가 닫히지 않았다는 의미 (예외처리 하세요) (했어요!)
		free (labels);
		return (0);
	}
	return (labels);

}

/*
** Parameter    : 	1. 셸의 입력 텍스트
**					2. 입력중인 라벨
**					3. 처리중인 텍스트와 라벨의 위치 
**					4. 텍스트의 길이
** Return value : 없음
** Description  :	발견한 i 부분이 quote라면 quote가 "닫힌 곳"까지 i를 이동시키고,
**				 	quote 부분의 라벨을 찍는다. 만약 quote가 닫히지 않았다면 
**					라벨의 맨 마지막 null문자까지 qoute 표시로 바꾸어 놓는다. 이는 label_text()에서 검사해야 한다.
** 완성됨
*/
static void mark_quote(char *text, char *labels, int *idx, int len)
{
	char q;
	char l;

	if (ft_isquote(text[*idx]))
	{
		q = text[*idx];
		if (q == '\'')	l = "qoute"[0];
		else			l = "double_quote"[0];
		labels[(*idx)++] = l;
		while(*idx <= len)
		{ 
			labels[*idx] = l;
			if (text[*idx] == q)
				return;
			(*idx)++;
		}
	}
	return ;
}

/*
** Parameter    : 	1. 셸의 입력 텍스트
**					2. 입력중인 라벨
**					3. 처리중인 텍스트와 라벨의 위치 
** Return value : 없음
** Description  :	i위치의 text를 보고 |, <, >, <space>, etc 에 따라서
**					각각, 문자         p, l, r,       s,   t 를 labels의 해당 위치에 넣는다. 
** 완성됨
*/
static void mark_not_quote(char *text, char *labels, int i)
{
	if (text[i] == '|')
		labels[i] = "pipe"[0];
	else if (text[i] == '>')
		labels[i] = "redirection"[0];
	else if (text[i] == '<')
		labels[i] = "ledirection"[0];
	else if (text[i] == ' ')
		labels[i] = "space"[0];
	else
		labels[i] = "text"[0];
}


int	main(int argc, char **argv, char **envp)
{
	char *s = "echo aaa | cat > \"a.txt||\" | chmod 755 < \'asd\" | < >asd \' asd";
	char *l;
	t_list *token_start;

	l = label_text(s);
	ft_printf("%s\n%s\n", s, l);

	tokenize("echo aaa > a.txt", &token_start);

	int i = -1;
	int len = ft_lstsize(token_start);

	while (++i < len)
		print_token(ft_lstnth(token_start, i)->content, "a", 0);

}
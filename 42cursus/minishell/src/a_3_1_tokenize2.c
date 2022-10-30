/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_3_1_tokenize2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:37:52 by balee             #+#    #+#             */
/*   Updated: 2022/10/27 11:31:01 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_token(t_token *token);
t_token	*new_token(char atype, char *atext);
void	print_token(t_token *token, char *name, int tabs);
int		tokenize(char *text, t_list **token_start);
t_list	*label2token(char *text, char *labels);
int		connect_token(t_list **token_start, t_list *token_node);
t_list	*make_token_here(char *text, char *labels, int i);
int		check_label(char *labels);
char	*label_text(char *text);
void	mark_quote(char *text, char *labels, int *idx, int len);
void	mark_not_quote(char *text, char *labels, int i);
int		check_token(t_list *token_start);
void	print_token_list(t_list *token_start, char *list_name);

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
t_list	*label2token(char *text, char *labels)
{
	int		i;
	int		len;
	t_list	*token_node;
	t_list	*token_start;

	token_start = 0;
	len = ft_strlen(text);
	i = 0;
	if (labels[i] != 's' && labels[i] != 'e')
	{
		token_node = make_token_here(text, labels, i);
		if (connect_token(&token_start, token_node))
			return (0);
	}
	while (++i < len)
	{
		if (labels[i] != 's' && labels[i] != 'e' && labels[i - 1] != labels[i])
		{
			token_node = make_token_here(text, labels, i);
			if (connect_token(&token_start, token_node))
				return (0);
		}
	}
	return (token_start);
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
int	connect_token(t_list **token_start, t_list *token_node)
{
	if (token_node == 0 || token_start == 0)
	{
		ft_lstclear(token_start, (void (*)(void *)) destroy_token);
		ft_lstdelone(token_node, (void (*)(void *)) destroy_token);
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
t_list	*make_token_here(char *text, char *labels, int i)
{
	int		len;
	t_list	*node;
	t_mbox	mbox;

	len = 0;
	while (labels[i + len] == labels[i])
		len++;
	if (labels[i + len] == "end_of_quote"[0])
		len++;
	mbox.cur = 0;
	node = collector(&mbox, ft_lstnew(collector(&mbox, \
		new_token(labels[i], collector(&mbox, ft_substr(text, i, len))))));
	if (!(mbox.cur == 3))
		return (collector(&mbox, 0));
	else
		return (node);
}

int	check_label(char *labels)
{
	int	len;

	if (!labels)
		return (1);
	len = ft_strlen(labels);
	if (ft_strnstr(labels, "pp", len))
		return (1);
	if (ft_strnstr(labels, "rl", len) != 0
		|| ft_strnstr(labels, "lr", len) != 0)
		return (1);
	if (ft_strnstr(labels, "rrr", len) != 0
		|| ft_strnstr(labels, "lll", len) != 0)
		return (1);
	if (ft_strlen_s(labels, "prlqdt") == (size_t) len)
		return (1);
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
char	*label_text(char *text)
{
	int		i;
	int		stat;
	int		len;
	char	*labels;

	len = ft_strlen(text);
	if (len == 0)
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
		free (labels);
		return (0);
	}
	return (labels);
}

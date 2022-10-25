/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:37:52 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 04:06:30 by balee            ###   ########.fr       */
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

void	destroy_token(t_token *token)
{
	if (token->text)
		free(token->text);
	free(token);
}

t_token	*new_token(char atype, char *atext)
{
	t_token	*r;

	r = ft_calloc(sizeof(t_token), 1);
	if (r)
	{
		r->type = atype;
		r->text = atext;
	}
	return (r);
}

void	print_token(t_token *token, char *name, int tabs)
{
	static char	n[1000];

	ft_bzero(n, 1000);
	ft_memset(n, '\t', int_min(tabs, 999));
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
int	tokenize(char *text, t_list **token_start)
{
	char	*labels;

	labels = label_text(text);	// 텍스트에 라벨을 붙입니다!
	if (DEBUG)	ft_printf("text  =%s\n", text);
	if (DEBUG)	ft_printf("label =%s\n", labels);
	if (check_label(labels))					// 라벨을 보고 잘못된 것을 걸러냅니다.
	{
		//라벨이 잘못된 경우 예외처리
		free(labels);
		return (1);
	}
	*token_start = label2token(text, labels);	// 토큰에 옮겨 담습니다.
	free(labels);					//라벨 다 썼으니 free
	if (check_token(*token_start))				// 토큰을 보고 잘못된 것을 걸러냅니다.
	{
		// 토큰이 이상한 경우 예외처리
		ft_lstclear(token_start, (void (*)(void *)) destroy_token);
		return (1);
	}
	return (0);									// 마무리하고 리턴하니다.
}

/*
** Parameter    : 	잘 연결된 토큰 연결리스트
**
** Return value : 	정상이면 0
**					비정상이면 1 또는 다른 숫자들
** Description  :   연결된 토큰들을 보고 걸러낼 수 있는 문맥 오류를 걸러냅니다.
**					정상적으로 실행할 수 있는 토큰 형식만을 통과시켜야 합니다.
**
**					이 함수가 발견할 수 있는 문제
**						1. pipe 다음에 pipe가 오는 경우
**							1-1. pipe 다음에 아무것도 오지 않는 경우
**						2. 리디렉션 토큰 다음 토큰이 text 토큰이 아닌 경우
**						3. 명령어가 될 text토큰이 없는 경우 (이건 이후에 확인 해야 할 것 같은데) (됬다!)
**						3-1. 시작하자 마자 파이프가 오는 경우;
**
** Implement	:	
**
** 완성됨(수정할때 위에 설명도 수정해주세요!)
*/

int	check_token(t_list *token_start)
{
	t_list	*p;
	t_token	*t;
	int		command_flag;

	command_flag = 1; // 이게 0이 되어야지 명령어가 될 text토큰이 있는 것
	p = token_start;
	while (p)
	{
		t = (t_token *)p->content;
		if (t->type == "pipe"[0])			// 이번 노드가 파이프인데
		{ 
			if (0 < command_flag)	//만약 파이프 이전에 명령어 부분이 될 text가 없었다면
				command_flag = -1;	//오류!!!
			if (p->next == 0 || ((t_token *)p->next->content)->type == "pipe"[0])		// 다음 노드가 없거나, 다음 노드도 파이프라면
				return (1);
		}
		if (t->type == "redirection"[0] || t->type == "ledirection"[0])			// 이번 노드가 리다이렉션인데
		{
			if (0 < command_flag)
				command_flag = 2;
			if (p->next && ((t_token *)p->next->content)->type != "text"[0]) // 다음 노드가 text가 아니라면
				return (1);
		}
		if (0 < command_flag)
			command_flag--;
		p = p->next;
	}
	if (command_flag) //만약 명령어 부분이 될 text 노드가 없다면,
		return (1);
	return (0);
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

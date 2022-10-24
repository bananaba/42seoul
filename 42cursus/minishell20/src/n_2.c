
#include "minishell.h"

//variable_expansion()
int			variable_expansion(t_list *token_start, t_list *envp);
int			variable_expansion_token(t_token *text_token, t_list *envp);
void		expande_str(char *buffer, char *str, t_list *envp);
int			expanded_lenght_of_str(char *str, t_list *envp);
char		*get_envp(char *str, t_list *envp);
static int	ft_varlen(char *str);




/*
** Parameter    : 토큰 연결 리스트의 시작 부분
** Return value : 처리 결과
**					0 : 처리가 정상적으로 완료됨
**					1 : 처리에 문제가 생김
** Description  : 토큰의 시작점을 받아서 토큰을 순회하며, type이 "text"[0]인 토큰과
**				  "double_quote"[0]인 토큰들의 문자열 중
**				  변수 부분을 해당하는 envp의 문자열로 교체한다.
**				  만약 처리에 문제가 생기면 연결리스트를 모두 지우고 1을 리턴한다.
**
**				 x  처리가 끝나면, 빈 내용의 토큰이 있을 수 있으니, 그것을 지워 주어야 한다. 
**				 (안 지우는게 맞는거 같다.) 
**					echo aa > $a > a.txt
**					zsh: no such file or directory: 
**
*/
int variable_expansion(t_list *token_start, t_list *envp)
{
	t_list *now;
	t_token *now_token;

	now = token_start;


	while (now)// 토큰을 순회하면서
	{
		now_token = (t_token *) now->content;
		if (DEBUG) print_token(now_token, "now_token", 0);


		if (now_token->type == "text"[0] || now_token->type == "double_quote"[0])//만약 토큰이 text이거나 double_quote이면
		{
			if (variable_expansion_token(now_token, envp))// expansion을 한다. expansion중 잘못되었다면
			{
				ft_lstclear(&token_start, destroy_token);// 토큰 연결리스트를 싹 지우고
				return (1);//1을 리턴한다.
			}
		}
		if (DEBUG) print_token(now_token, "processed_token", 1);
		now = now->next;// 
	}

	return (0);// 정상적으로 expansion되면 0을 리턴한다.

}

/*
** Parameter    : "text"[0] 타입의 토큰 하나의 주소
** Return value : 처리 결과
**					0 : 처리가 정상적으로 완료됨
**					1 : 처리에 문제가 생김
** Description  : 토큰의 문자열을 보면서 변수 부분을 해당하는 envp의 값으로 대체한다.
**	
*/
int variable_expansion_token(t_token *text_token, t_list *envp)
{
	char	*str;
	char	*result;
	int		len;

	
	str = text_token->text;

	result = 0;

	len = expanded_lenght_of_str(str, envp);// 필요한 문자열의 길이를 구한다.

	if (0 <= len)//길이가 잘 구해졌다면 (expansion을 해야 한다는 이야기네)
	{
		result = ft_calloc(sizeof(char) , len + 31);// 마음의 평화를 위해 30만큼 더 줌 
		if (result)// 만약 정상적으로 메모리가 주어졌다면
		{
			expande_str(result, str, envp);// exansion 한 문자열을 얻고
			free(str);
			text_token->text = result;//교체한다.
			return(0);
		}
	
	}
	return (1);
}


/*
** Parameter    : 결과를 저장할 메모리 위치, 확장할 문자열, 변수 목록
** Return value : 이건 void 해도 되겠다. // 왜냐하면 expanded_lenght_of_str 
**					의 결과가 1 이상이 나왔다는 것은, 문제가 없다는 뜻이니까
** 
**
** Description  : str의 변수 이름을 envp의 변수 내용으로 대치한다. 그리고 그걸 버퍼에 쓴다.
**	
** 중요			:	(만약 expanded_lenght_of_str 함수랑 처리 루틴이 달라지면,
**					오류가 날 수 있어 (중간에 envp가 바뀐다던지))
*/
void expande_str(char *buffer, char *str, t_list *envp)
{
	int i;
	int temp_len;
	char *temp_str;

	i = 0;

	while(str[i])
	{
		//커서 위치부터 다음 $ 이전까지 문자를 포함하는 문자열을 buffer에 쌓는다.
		temp_len = ft_strlen_c(&str[i], '$');
		ft_strlcat(buffer, &str[i], ft_strlen(buffer) + temp_len + 1);// $ 전 까지 복사
		i += temp_len; // 커서를 $ 위치로 옮긴다.

		if (str[i])
			i++;
		//$의 다음 문자부터, 변수를 찾아 buffer에 쌓는다.
		temp_str = get_envp(&str[i], envp);
		if (DEBUG) ft_printf("\ttemp_str = %s\n", temp_str);
		if (temp_str)
		{
			ft_strlcat(buffer, temp_str, ft_strlen(buffer) + ft_strlen(temp_str) + 1);
		}
		i += ft_varlen(&str[i]);
	}
}


/*
** Parameter    : 변수가(0개 이상) 포함된 문자열괴 변수 목록 envp
** Return value : 처리 결과
**					1 이상 : 모든 변수이름이 변수로 치환되었을때 필요한 문자열의 총 길이
**					0, : 일단은 다 치환했더니 0 이었다고 하자.
**					- 1 : 계산에 문제가 생김 (토큰에 빈 문자열은 있을 수 없으니까)
** Description  : 문자열의 모든 변수를 치환하였을 때 예상되는 문자열의 길이를 계산하여 리턴한다.
**	
*/
int expanded_lenght_of_str(char *str, t_list *envp)
{
	char *t;
	int i;
	int len;

	i = 0;
	len = 0;

	while(str[i])
	{
		if (str[i] == '$')// 만약 변수가 시작되는 것 같으면
		{
			t = get_envp(&str[++i], envp);
			/*//V1 없는 변수는 문자열로 취급하는 버전 
			if (t) // 만약 변수가 진짜 있으면
			{
				i += ft_varlen(str[i]);//i를 변수이름 길이만큼 추가해서, 변수 이름 다음 부분을 가르킴
				len += ft_strlen(t);//len을 변수 길이만큼 추가함
			}
			else//아니면 (이거 약간 수정할 필요가 있겠다 bash는 인식 한 부분만큼 그냥 지워 버리네)
			{
				len++;//아까 올려놓은 i
			}
			*/
			
			//V2 이게 bash처럼 없는 변수는 그냥 자워 버리는 버전
			if (t) // 만약 변수가 진짜 있으면
			{	
				len += ft_strlen(t);//len을 변수 길이만큼 추가함
			}// 없으면 그냥 자워지는 거야!
			i += ft_varlen(&str[i]);//i를 변수이름 길이만큼 추가해서, 변수 이름 다음 부분을 가르킴
		}	
		else// 변수가 시작되는 것 같지 않으면
		{// 하나씩 더해간다.
			len++;
			i++;
		}
	}
	return (len);
}


/*
** Parameter    : 변수 이름 문자열, 스트링 연결리스트로 표현된 envp
** Return value : envp에서해당하는 변수의 내용이 시작하는 문자를 가르키는 포인터
**				  0 : 만약 일치하는 변수가 없다면, null포인터
**
** Description  : envp에서 입력받은 str과 일치하는 변수 이름을 찾으면
**					그 내용 부분의 맨 앞 위치의 포인터를 리턴합니다.
**				  만약 찾지 못하면
**					0 포인터를 리턴합니다.
*/
char *get_envp(char *str, t_list *envp)
{
	t_list *now;

	now = envp;

	while(now)//envp를 순회한다.
	{
		if (ft_strncmp(str, now->content, 
				int_max(ft_strlen_c(now->content , '='), ft_varlen(str))
			) == 0)// str과 envp중 하나를 비교한다. -> 비교 길이는 (str의 변수길이와, envp의 변수 길이) 중 긴걸로 한다.
		{
			return (ft_strchr(now->content, '=') + 1);//만약 같은 게 있다면 변수 내용이 시작하는 위치를 리턴한다.
		}
		now = now->next;
	}
	return (0);
}


/*
** Parameter    : 변수 이름이 시작되는 $다음의 문자열
** Return value : 해당 문자열이 시작되는 부분부터 시작하는 변수 이름의 길이
**				  
**
** Description  : 변수의 이름이 시작하는 &문자 다음 문자의 위치를 포인터로 찍어서 받으면
**					변수 이름 규칙을 따르는 변수 이름의 길이를 리턴한다.
**
*/
static int ft_varlen(char *str)
{
	int i;

	i = 0;

	if (str[i] == '?')
		return (1); 

	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;

	return i;
}




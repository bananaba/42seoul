#include "minishell.h"

int variable_expansion(t_mp *mp, t_list *list)
{
	int 	i;
	char	*temp_str;
	t_list	*node;
	i = -1;

	while(ft_lstnth(list, ++i))
	{
		node = ft_lstnth(list, i);
		//ft_printf("debug8 : %p\n", node);
		//ft_printf("debug8 : %p\n", node->content);
		if (((char *) node->content)[0] != '\'')
		{
			temp_str = node->content;
			node->content = variable_expansion_str(temp_str, mp->envp);
//			ft_printf("debug 15 : %s\n", node->content);
			free(temp_str);
		}
	}
	return (0);	
}
		//이제 여기서 문자 찾고 확장만 하면 된다.


// 문자열을 받으면, 거기서 $를 변환해서 새로운 할당한 메모리에 담아 반환.
char *variable_expansion_str(char *str, t_list *envp)
{
	int i;
	int len;
	char *temp_str;
	char *r;

	i = 0;
	len = 0;
	// 먼저 전체 길이 계산.
//	ft_printf ("debug 16 : %p\n", str);
//	ft_printf ("debug 16 : %s\n", str);
//	ft_printf ("debug 16 : %c\n", str[i]);

	while(str[i])
	{
		if (str[i] == '$')
			len += ft_strlen(find_and_get_envp(str, &i, envp));
		else
			len++;
		i++;
	}
	r = ft_calloc(sizeof(char), len + 5);
	i = 0;
	// 이제 옮겨 담는다..
	while(r && ft_strchr(&str[i], '$'))
	{
		ft_strlcat(r, &str[i], ft_strlen(r) + ft_strlen_c(&str[i], '$') + 1);
		i += ft_strlen_c(&str[i], '$');
		temp_str = find_and_get_envp(str, &i, envp);
		if (temp_str == 0)
			ft_strlcat(r, "$", ft_strlen(r) + 1 + 1);
		else
			ft_strlcat(r, temp_str, ft_strlen(r) + ft_strlen(temp_str) + 1);
		i++;
	}
	if (r)
		ft_strlcat(r, &str[i], ft_strlen(r) + ft_strlen(&str[i]) + 1);
	return (r);

}

// envp의 문자열에서 = 다음의 문자를 가르키는 포인터를 리턴한다.
// 고로 free해 줄 필요 없음
// i도 필요한 만큼 자동 스킵해줌(문자열의 끝까지 넘겨줌 ++하면 변수의 다음 문자)
char *find_and_get_envp(char * str, int *index, t_list *envp)
{
	// 일단 $부터 해서 변수를 찾아야겠지
	// 찾으면 = 다음부터 리턴하고
	// 변수명 길이만큼 i를 늘린다.

	int env_i;
	int max_matched_len;// 가장 길게 매칭된 (envp)인덱스
	int max_matched_index;// 매칭된 최대일치 변수의 이름길이가 들어간다.
	char *env_str;

	env_i = -1;

	while(ft_lstnth(envp, ++env_i))
	{
		env_str = ft_lstnth(envp, env_i)->content;
		// env_str과
		if (str[*index + 1] && ft_strncmp(env_str, &str[*index + 1], \
			int_max(ft_strlen_c(&str[*index + 1], ' '), ft_strlen_c(env_str, '='))) \
			 == 0 )
		{
			*index += ft_strlen_c(env_str, '=');
			return (ft_strchr(env_str, '=') + 1); 					// 문자열의 위치
		}
	}
	return (0);
	// envp의 문자열에서 = 다음의 문자를 가르키는 포인터를 리턴한다.
}


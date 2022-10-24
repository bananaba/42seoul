#include "minishell.h"


int parse_structure(t_mp *mp, t_r *runnable);
int split_into_excutables(t_mp *mp, t_r *runnable);
int parse_excutables_text(t_r *runnable);

// runnable을 돌면서
// excutable의 text 맨 위에 공백을 하나 집어넣고
// excutable의 파싱용 텍스트 변수에 리다이렉션과 명령어를 채워넣는다.

int parse_excutables_text(t_r *runnable)
{
	int i;
	char *temp_str;
	t_e *exc;

	i = -1;

	while(runnable->excutables[++i])
	{
		exc = runnable->excutables[i];
		exc -> excutable_path = ft_calloc(sizeof(char), ft_strlen(exc->text) + 1);
		exc -> redirections = ft_calloc(sizeof(char), ft_strlen(exc->text) + 1);
		temp_str = ft_mprintf("%s ", exc -> text);
		free(exc->text);
		exc->text = temp_str;

		excutable_tokenize(exc->text, exc->redirections, exc->excutable_path);
		ft_printf("redirection :%s \n", exc->redirections);
		ft_printf("excutable   :%s \n", exc->excutable_path);
	}
	return (0);
}

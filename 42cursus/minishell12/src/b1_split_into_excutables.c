#include "minishell.h"

//runnable을 받아서 거기에 저장되어 있는 text를 보고
// 파이프 단위로 나누어서 excutable을 생성하고 각각 담은 뒤
// runnable의 excutables에 포인터 리스트로 담아둔다, 맨 마지막 excutable 뒤의 값은 0 포인터 (리스트의 끝을 알려줌)
int split_into_excutables(t_mp *mp, t_r *runnable)
{

	t_mbox	trash_can;
	char	**pipe_split;
	int 	i;
	int		cut_start;
	t_list 	*cmd_list;
	char c;
	
	cmd_list = 0;
	i = 0;
	cut_start = 0;
	while(runnable->text[i])
	{
		if (runnable->text[i] == '|')
		{
			ft_lstadd_back(&cmd_list, ft_lstnew(ft_substr(runnable->text, cut_start, i - cut_start)));
			cut_start = ++i;
		}
		else if (runnable->text[i] == '\'' || runnable->text[i] == '\"')
		{
			skip_quote(runnable->text, &i);
			i++;
		}
		else
		{
			i++;
		}
	}	// 마지막에 쿼트 빠진 경우 오류처리 해야됨
	//ft_printf("debug4 : %s %i %i\n", runnable->text, cut_start, i-cut_start);
	ft_lstadd_back(&cmd_list, ft_lstnew(ft_substr(runnable->text, cut_start, i - cut_start)));
	trash_can.cur = 0;
	//collector(&trash_can, 0);//initialize
	
	pipe_split = ft_split(runnable->text, '|'); // malloc 예외처리
	if (pipe_split == 0)
	{
		runnable->state = 100;
		return (0);
	}
	pipe_split = strlist_2_splited(&cmd_list);
	ft_lstclear(&cmd_list, free);

	//printf("debug3 : %s\n", pipe_split[1]);
	//job을 받아서 그 텍스트 내용을 토대로
	// excutable을 만들고 그안에 텍스트 구겨담기
	i = -1;
	runnable->num_of_excutables = 0;

	while (pipe_split[runnable->num_of_excutables])
		runnable->num_of_excutables++;
	
	runnable->excutables = ft_calloc(sizeof(t_e), runnable->num_of_excutables + 1);
	runnable->excutables[runnable->num_of_excutables] = 0;

	while (pipe_split[++i])//job 만들고 그 안에 excutable 옮겨담기 (excutable 만들기)
	{
		runnable->excutables[i] = ft_calloc(sizeof(t_e), 1);
		if (collector(&runnable->mbox, runnable->excutables) == 0) // malloc 예외처리
			return (0);
		runnable->excutables[i]->text = pipe_split[i]; // 자 할일 다 했다 다음으로 넘어가자
		runnable->excutables[i]->envp = &mp->envp;

	}
	free (pipe_split); // 여기까지 excutable 만들어서 text 옮겨닯기 끝, envp 주소도 넘겨줌

	// 그 다음은 excutable 마다 리디렉션을 들어내서 저장하는 것
	// 리디렉션을 들어낼 때에는 따옴표에 주의하여 들어내야 한다.
	return (0);
}

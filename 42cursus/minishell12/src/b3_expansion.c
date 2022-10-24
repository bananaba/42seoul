#include "minishell.h"


int expansion(t_mp *mp, t_r *runnable);
t_list *split_by_quote(char * str);

int expansion(t_mp *mp, t_r *runnable)
{
	int i;
	t_e *excutable;

	t_list				*path_list;
	t_list				*redirection_list;

	i = -1;
	//ft_printf("debug6 : %p\n", runnable);
	//ft_printf("debug6 : %p\n", runnable->excutables);

	//ft_printf("debug5 : %d\n", i);

	while(runnable->excutables[++i])
	{
		//ft_printf("debug5 : %d\n", i);
		excutable = runnable->excutables[i];

	//텍스트 익스펜션
		//쿼터 단위로 나눈다. asd fgh"zxc" vbn -> asd fgh|"zxc"| vbn
			path_list = split_by_quote(excutable->excutable_path);
			print_strlist(path_list, "after split");		
		//나누어진 항목 별로 변수확장, 이름 확장을 한다.
			variable_expansion(mp, path_list);
			print_strlist(path_list, "after variable_expansion");
			//filename_expansion(path_list);
		//순서대로 잘라서 argv에 넣는다. 쿼터는 통채로 넣는다, 이때 따옴표를 지운다.
			int j = -1;
			//ft_printf("debug9 :%s\n", ((char *) ft_lstnth(path_list, i)->content));
//			while(ft_lstnth(path_list, ++j))
//				ft_printf("debug9 : each expanded path_list :%s\n", ((char *) ft_lstnth(path_list, j)->content));
			path_list_interpret(excutable, path_list);
			print_excutable(excutable, "after path_list_interpret");
			//find_argv0(excutable);
	

	//리다이렉스 익스펜션
		//리다이렉션도 쿼터 단위로 나누다.
			//redirection_list = split_by_quote(excutable->excutable_path);

		// 나누어진 항목 별로 변수확장, 이름 확장을 한다.
			//variable_expansion(redirection_list);
			//filename_expansion(redirection_list);
		// 순서대로 잘라서 넣는다.
			//redirection_list_interpret(excutable, redirection_list);

		//ft_printf("redirection : %s \n", exc->redirections);
		//ft_printf("excutable   : %s \n", exc->excutable_path);
	}
	return (0);



	//t_list *exc_list;

	
	//excutable_text 는 파이플를 띄어쓰기로 교체 하고, 한 문장에서 바로 확장한다. 
}


t_list *split_by_quote(char * str)
{
	int 	i;
	int		cut_start;
	t_list 	*str_list;

	i = 0;
	cut_start = 0;
	str_list = 0;
	
	while(str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			ft_lstadd_back(&str_list, ft_lstnew(ft_substr(str, cut_start, i - cut_start)));
			cut_start = i;
			skip_quote(str, &i);
			i++;
			ft_lstadd_back(&str_list, ft_lstnew(ft_substr(str, cut_start, i - cut_start)));
			cut_start = i;
		}
		else
		{
			i++;
		}
	}
//	printf("debug7 : %s %i %i\n", str, cut_start, i - cut_start);
	ft_lstadd_back(&str_list, ft_lstnew(ft_substr(str, cut_start, i - cut_start)));

	return (str_list);
}

/*
t_list *split_by_quote(char * str)
{
	int 	i;
	int		cut_start;
	t_list 	*str_list;

	i = 0;
	cut_start = 0;
	str_list = 0;
	
	while(str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			ft_lstadd_back(&str_list, ft_lstnew(ft_substr(str, cut_start, i - cut_start)));
			cut_start = i;
			skip_quote(str, &i);
			i++;
			ft_lstadd_back(&str_list, ft_lstnew(ft_substr(str, cut_start, i - cut_start)));
			cut_start = i;
		}
		else
		{
			i++;
		}
	}
//	printf("debug7 : %s %i %i\n", str, cut_start, i - cut_start);
	ft_lstadd_back(&str_list, ft_lstnew(ft_substr(str, cut_start, i - cut_start)));

	return (str_list);
}*/




/*
int get_envp_size(t_list *envp)
{
	return(ft_lstsize(envp));
}

int variable_expansion(t_mp *mp, char *str)
{
	int len;
	int *matched_length;
	char *line_of_envp;

	len = get_envp_size(mp->envp);
	matched_length = ft_calloc(sizeof(int), len);

	int i = -1;

	while (ft_lstnth(++i))
	{
		line_of_envp = ft_lstnth(mp->envp, i)->content;
		if (ft_strncmp(str, line_of_envp, ft_strlen_c(line_of_envp, '=')) == 0)
			matched_length[i] == ft_strlen_c(line_of_envp, '=');
	}


}
*/